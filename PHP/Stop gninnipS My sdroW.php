<?php
    /* 
        Stop gninnipS My sdroW!  | 6 kyu
        
        Write a function that takes in a string of one or more words, and returns the same string, 
        but with all five or more letter words reversed (Just like the name of this Kata). 
        Strings passed in will consist of only letters and spaces. 
        Spaces will be included only when more than one word is present.
        Examples:   spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" 
                    spinWords( "This is a test") => returns "This is a test"
                    spinWords( "This is another test" )=> returns "This is rehtona test"
    */ 
    function spinWords(string $str): string {
        $array = explode(" ", $str);
        for($i = 0; $i < count($array); $i++){
            if(strlen($array[$i]) > 4){
                $array[$i] = strrev($array[$i]);
            }
        }
        return join(" ", $array);
    }
    echo spinWords("Hey fellow warriors");
?>
