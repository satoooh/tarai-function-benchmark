<?php

function tarai($x, $y, $z) {
    if ($x <= $y) {
        return $y;
    } else {
        return tarai(tarai($x - 1, $y, $z),
                     tarai($y - 1, $z, $x),
                     tarai($z - 1, $x, $y));
    }
}

$n_iter = 10;
$times = [];

for ($i = 0; $i < $n_iter; $i++) {
    $start_time = microtime(true);
    tarai(13, 5, 0);
    $end_time = microtime(true);
    $elapsed_time = $end_time - $start_time;
    $times[] = $elapsed_time;
}

$average_time = array_sum($times) / count($times);
$std_time = 0;
foreach ($times as $time) {
    $std_time += pow($time - $average_time, 2);
}
$std_time /= count($times);
$std_time = sqrt($std_time);

echo "PHP version: " . PHP_VERSION . "\n";
echo "Average elapsed_time: " . $average_time . " sec\n";
echo "Standard deviation: " . $std_time . " sec\n";
?>
