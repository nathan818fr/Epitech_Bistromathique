<?php
function randomNumber($maxSize, $baseLen)
{
  global $baseChar;

  $nb = (rand(0, 1) == 0) ? "-" : "";
  $size = rand(1, $maxSize);
  for ($i = 0; $i < $size; $i++)
    {
      $nb.= $baseChar[rand($i == 0 ? 1 : 0, $baseLen - 1)];
    }
  return ($nb);
}

$baseChar = "0123456789abcdef";
$operators = array('+', '-', '*');
$operators2 = array('/', '%');

$e = array(
	   "1+1",
	   "99+1",
	   "9999999999999990+111111",
	   "-26+101",
	   "-269+-234",
	   "11+(-77)",
	   
	   "1-9",
	   "9-1",
	   "999-1",
	   "1-999",
	   "0-172",
	   "172-0",
	   "0-0",

	   "152*26",
	   "26*152",
	   "1*1637383",
	   "0*0",
	   "1*1",
	   "-162*177",
	   "162*-177",
	   "-162*-177",

	   "123/234",
	   "234/123",
	   "1/0",
	   "0/1",
	   "-555/23",
	   "555/-23",
	   "-0/-0",
	   "155273737/1",
	   "1/153766332",

	   "99%22",
	   "22%99",
	   "-99%22",
	   "22%-99",
	   "-22%-99",

	   "0",
	   "-1",
	   "1",

	   "0-987654321098765432109876543210+(123456789*987654321)*((50%23)/(2-1))",
	   "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1"
);

$eTestInd = 0;
while (true)
{
$baseLen = 10;
$nbCount = 0;

 if ($eTestInd >= count($e))
   exit();
$expr = $e[$eTestInd];
$eTestInd++;

echo "\n" . $expr . "\n";

$descriptorspec = array(
			0 => array("pipe", "r"),
			1 => array("pipe", "w")
			);

$calcBase = "";
for ($i = 0; $i < $baseLen; $i++)
  $calcBase.= $baseChar[$i];

$calcCmd = '../calc "' . $calcBase . '" "()+-*/%" ' . strlen($expr);
//echo $calcCmd . "\n";

$timeStart = microtime(true);
$process = proc_open($calcCmd, $descriptorspec, $pipes);
if (is_resource($process)) {
  fwrite($pipes[0], $expr);
  fclose($pipes[0]);

  $calcRes = stream_get_contents($pipes[1]);
  fclose($pipes[1]);

  proc_close($process);

  echo "Calc: " . $calcRes . "\n";
 }


$bcCmd = "bc";

$process = proc_open($bcCmd, $descriptorspec, $pipes);
if (is_resource($process)) {
  fwrite($pipes[0], 
	 "ibase=" . strtoupper($baseChar[$baseLen]) . ";" .
	 "obase=" . strtoupper($baseChar[$baseLen]) . ";" . 
	 strtoupper($expr) . "\n");
  fclose($pipes[0]);

  $bcRes = strtolower(stream_get_contents($pipes[1]));
  fclose($pipes[1]);

  proc_close($process);

  $bcRes = substr($bcRes, 0, -1);
  $bcRes = preg_replace("#\\\\\n#", "", $bcRes);
  echo "Bc  : " . $bcRes . "\n";
 }

 if ($calcRes != $bcRes)
   {
     echo "\n\n/!\ ERROR!\n";
     exit(true);
   }
 else
   {
     echo "OK\n";
   }
 sleep(1);
}