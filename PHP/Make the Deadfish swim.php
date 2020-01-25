<?php
    /*
        Make the Deadfish swim | 6kyu
        Write a simple parser that will parse and run Deadfish.
        Deadfish has 4 commands, each 1 character long:
        • i increments the value (initially 0)
        • d decrements the value
        • s squares the value
        • o outputs the value into the return array
        Invalid characters should be ignored.
        Example: parse("iiisdoso") => [ 8, 64 ]
    */
    function parse($data) {
        $res = array();
        $score = 0;
        for($i = 0; $i < strlen($data); $i++){
            if($data[$i] == 'i'){
                $score++;
            }else if($data[$i] == 'd'){
                $score--;
            }else if($data[$i] == 's'){
                $score *= $score;
            }else if($data[$i] == 'o'){
                array_push($res, $score);
            }
        }
        return $res;
    }
     print_r(parse("iiisdoso"));
?>