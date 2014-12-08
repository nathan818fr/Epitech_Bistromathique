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

$isRunning = true;
$runCount = 1;

while ($isRunning)
{
$baseLen = rand(2, 15);
$nbCount = rand(1, min($runCount * $runCount, 15000));
 if ($argv[1] == 0)
   $nbCount = rand(1, 10000);
$brackets = 0;
$expr = "";

$runCount++;

for ($i = 0; $i < $nbCount; $i++)
  {
    if ($i != 0)
      {
	if (rand(0, 99) < 95)
	  $expr.= $operators[rand(0, count($operators) - 1)];
	else
	  $expr.= $operators2[rand(0, count($operators2) - 1)];
      }
    if (rand(0, 99) < 50)
      {
	$expr.= '(';
	$brackets++;
      }
    $nb = randomNumber(25, $baseLen);
    if ($nb[0] == '-')
      $expr.= '(' . $nb . ')';
    else
      $expr.= $nb;
    if ($brackets > 0 && rand(0, 99) < 50)
      {
	$expr.=')';
	$brackets--;
      }
  }
while ($brackets > 0)
  {
    $expr.=')';
    $brackets--;
  }

echo $expr . "\n\n";

$descriptorspec = array(
			0 => array("pipe", "r"),
			1 => array("pipe", "w")
			);

$calcBase = "";
for ($i = 0; $i < $baseLen; $i++)
  $calcBase.= $baseChar[$i];

$calcCmd = '../calc "' . $calcBase . '" "()+-*/%" ' . strlen($expr);
//if ($argv[1] == 0)
//$calcCmd = "valgrind --leak-check=full " . $calcCmd;
//echo $calcCmd . "\n";

$timeStart = microtime(true);
$process = proc_open($calcCmd, $descriptorspec, $pipes);
if (is_resource($process)) {
  fwrite($pipes[0], $expr);
  fclose($pipes[0]);

  $calcRes = stream_get_contents($pipes[1]);
  fclose($pipes[1]);

  proc_close($process);

  echo "BASE LEN   : " . $baseLen . "\n";
  echo "OPERATIONS : " . $nbCount . "\n";
  echo "EXEC TIME CALC : " . (microtime(true) - $timeStart);
  echo "\n";
  echo "Calc: " . $calcRes . "\n";
 }


$bcCmd = "bc";

$timeStart = microtime(true);
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
  echo "EXEC TIME BC : " . (microtime(true) - $timeStart);
  echo "\n";  
  echo "Bc  :  " . $bcRes . "\n";
 }

 echo "\n--\n\n";
 
if ($calcRes != $bcRes)
  {
    $isRunning = false;
    echo "\n\n/!\ ERROR!\n";
  }

if ($argv[1] != 1)
  $isRunning = false;
//sleep(1);
}