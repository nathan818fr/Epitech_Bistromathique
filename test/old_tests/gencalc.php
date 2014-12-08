<?php
$str = '';
$ops = array('+', '-', '*');
$ops2 = array('*');
//$ops = array('+', '-', '*', '/');
//$ops2 = $ops;
$bra = 0;

$pnb = 0;
$pop = '';
$imax = rand(4, 80);
$imax = 5000;
for ($i = 0; $i < $imax; $i++)
{
  if ($i != 0)
    {
      if (rand(0, 99) < 98)
        $pop = $ops[rand(0, count($ops) - 1)];
      else
        $pop = $ops2[rand(0, count($ops2) - 1)];
      $str.= $pop;
    }
  if (rand(0, 1) == 0)
    {
	$str.= '(';
        $bra++;
    }
  $nb = rand(-PHP_INT_MAX, PHP_INT_MAX);
  if ($pop == '/' || $pop == '%')
    {
      if ($nb == 0)
        $nb = 1;
      if (abs($nb) > abs($pnb))
        $nb = $pnb;
    }
  $pnb = $nb;
  if ($nb < 0)
     $str.= '('.$nb.')';
  else
     $str.= $nb;
  if ($bra > 0 && rand(0, 1) == 0)
   {
	$str.= ')';
	$bra--;
   }
}
while ($bra > 0)
{
    $str.= ')';
    $bra--;
}
echo $str;