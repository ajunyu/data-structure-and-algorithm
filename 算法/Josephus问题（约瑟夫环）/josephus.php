<?php

// N人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的人。
$arr = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'];
$arrLength = count($arr);
$outNum = 3;    // 叫到 3 的出局
$num = 1;       // 报数从 1 开始
$index = 0;

while ($arrLength > 1) {
    if ($num % $outNum != 0) {
        $index = ($index + 1 == $arrLength) ? 0 : $index + 1;
    } else {
        array_splice($arr, $index, 1);
        $arrLength--;
        $index = ($index == $arrLength) ? 0 : $index;
    }
    $num++;
}

var_dump($arr);
