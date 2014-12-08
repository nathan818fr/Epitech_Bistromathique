<?php
class Base
{
  private	$base;
  private	$baselen;

  public function __construct($base)
  {
    $this->base = $base;
    $this->baselen = strlen($base);
  }

  public function getBase()
  {
    return ($this->base);
  }

  public function getBaselen()
  {
    return ($this->baselen);
  }

  public function getDigit($pos)
  {
    return ($this->base[$pos]);
  }

  public function digitValue($digit)
  {
    for ($i = 0; $i < $this->baselen; $i++)
	if ($this->base[$i] == $digit)
	  return ($i);
    return (0);
  }

  public function randomDigit($allowZero = true)
  {
    return ($this->base[rand($allowZero ? 0 : 1, $this->baselen - 1)]);
  }

  public function randomNumber($maxlen = 20)
  {
    $nb = "";
    $len = rand(1, $maxlen);
    while ($len > 0)
      {
	$nb.= $this->randomDigit($nb != "");
	$len--;
      }
    return ($nb);
  }

  public function numberToDec($number)
  {
    $nb = 0;
    $nblen = strlen($number);
    for ($i = 0; $i < $nblen; $i++)
      {
	//echo $this->digitValue($number[$i]) * pow(10, $nblen - $i - 1) . "\n";
	$nb += $this->digitValue($number[$i]) * pow(10, $nblen - $i - 1);
      }
    return ($nb);
  }

  public static function createRandomBase()
  {
    $rand_base = "";
    $rand_baselen = rand(2, 32);
    while ($rand_baselen > 0)
      {
	$chr_min = 32;
	$chr_max = 126;
	$chr_range = $chr_max - $chr_min;
	$rand_chr = chr(rand($chr_min, $chr_max));
	while (strpos($rand_base, $rand_chr) !== false ||
	       strpos("()+-*/%`'\"&!", $rand_chr) !== false)
	  $rand_chr = chr(
			  $chr_min + ((ord($rand_chr) - $chr_min + 1) % $chr_range)
			  );
	$rand_base.= $rand_chr;
	$rand_baselen--;
      }
    $base = new Base($rand_base);
    return ($base);
  }
}

$calc = "";
$calcDec = "";

$base = Base::createRandomBase();
$nbCount = rand(1, 100);
for ($i = 0; $i < $nbCount; $i++)
  {
    if ($i != 0)
      {
	$calc.= '+';
	$calcDec.= '+';
      }
    $nb = $base->randomNumber(8);
    $calc.= $nb;
    $calcDec.= $base->numberToDec($nb);
  }
$descriptorspec = array(
			0 => array("pipe", "r"),
			1 => array("pipe", "w")
			);

$cmd = '../calc "'.$base->getBase().'" "()+-*/%" ' . strlen($calc);
echo $calc . "\n";
echo "| " . $cmd . "\n";
$process = proc_open($cmd, $descriptorspec, $pipes);
if (is_resource($process)) 
  {
    fwrite($pipes[0], $calc);
    fclose($pipes[0]);

    $calcRes = stream_get_contents($pipes[1]);
    fclose($pipes[1]);

    echo $calcRes . "\n";
    echo $base->numberToDec($calcRes) . "\n";
  }

echo eval("return " . $calcDec . ";");