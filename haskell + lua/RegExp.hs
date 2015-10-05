--Eli ALlen
--CSCI 450
--Homework 3


-----------------------------------------------------------------------
--
-- 	Haskell: The Craft of Functional Programming, 3e
-- 	Simon Thompson
-- 	(c) Addison-Wesley, 1996-2011.
-- 
-- 	Chapter 12, Section 3: Recognizing Regular Expressions
--
------------------------------------------------------------------------

module RegExp where

import Data.List (foldl1)

type RegExp = String -> Bool

epsilon :: RegExp
epsilon = (=="")

char :: Char -> RegExp
char ch = (==[ch])

(|||) :: RegExp -> RegExp ->  RegExp
e1 ||| e2 = 
    \x -> e1 x || e2 x

(<*>) :: RegExp -> RegExp ->  RegExp
e1 <*> e2 =
    \x -> or [ e1 y && e2 z | (y,z) <- splits x ]

splits :: String -> [(String,String)]
splits xs = [splitAt n xs | n<-[0..len]]
    where
      len = length xs

(<**>) :: RegExp -> RegExp ->  RegExp
e1 <**> e2 =
    \x -> or [ e1 y && e2 z | (y,z) <- fsplits x ]

star :: RegExp -> RegExp
star p = epsilon ||| (p <**> star p)
--           epsilon ||| (p <*> star p)
-- is OK as long as p can't have epsilon match

fsplits :: String -> [(String,String)]
fsplits xs = tail (splits xs)

-- define a few char patterns for use in exercises
a,b :: RegExp
a = char 'a'
b = char 'b'

--- End of base program for assignment



--12.14
--star((a ||| b) <*> (a ||| b) matches any string with an even number of a's and/or b's or the empty string. 
--some examples: 
--star((a ||| b) <*> (a ||| b) "" = True 
--star((a ||| b) <*> (a ||| b) "aa" = True
--star((a ||| b) <*> (a ||| b) "bb" = True
--star((a ||| b) <*> (a ||| b) "ab" = True
--star((a ||| b) <*> (a ||| b) "aababb" = True
--star((a ||| b) <*> (a ||| b) "a" = False
--star((a ||| b) <*> (a ||| b) "b" = False
--star((a ||| b) <*> (a ||| b) "bba" = False 
--star((a ||| b) <*> (a ||| b) "c" = False
--star((a ||| b) <*> (a ||| b) "cc" = False




--12.15 
--Similarly to 12.5, star (star((a ||| b) <*> (a ||| b)) matches any empty string or string with an even number of 'a's and/or 'b's. The additional star closure doesn't change anythign
--All examples for 12.4 apply to the new regular expression


--12.16

--Define function option where option e matches zero or one occurance of pattern e
option :: RegExp -> RegExp
option e = (epsilon ||| e)

--Define function plus where plus e matches one or more occurences of pattern e
plus :: RegExp -> RegExp
plus e = e <*> star(e) -- I used <*> as opposed to <**> for the case where pattern e is epsilon ""


--12.17

--RegExp that matches strings of digits which begin with a non-zero digit
nonZero :: RegExp
nonZero = range '1' '9' <**> star(nonZero ||| zero)

--RegExp that matches two strings of digits separated by '.' with no superfluous zeroes
--Note that I intentionlly don't accept a number like "1.0" because it is not specified whether that zero is superfluous
fractNum :: RegExp
fractNum = nonZero <*> star(nonZero ||| zero ) <*> decimal <*> star(nonZero ||| zero) <*> nonZero

decimal :: RegExp
decimal = (==".")

zero :: RegExp
zero = (=="0")


range :: Char -> Char -> RegExp
range a b = \x -> length x == 1 && elem(head x)[a..b] 




--12.18

--regular expression describing all strings of 'a's and 'b's of length at most 3
threeab:: RegExp
threeab = (a ||| b) <*> (a ||| b) <*> (a ||| b) 

--regular expression describing all strings of 'a's and 'b's containing exactly two 'a's 
exactlyTwoA :: RegExp
exactlyTwoA = star(b) <*> a <**> star(b) <**> a <**> star(b) 



--test for option
test_option = 
  do
    putStrLn "Testing function option"
    putStr "option a \"a\"  = "
    putStrLn (show (option a "a"))
    putStr "option a \"b\"  = "
    putStrLn (show (option a "b"))
    putStr "option a \"\"  = "
    putStrLn (show (option a ""))
    putStr "option a \"aa\"  = "
    putStrLn (show (option a "aa"))
    putStr "option b \"b\"  = "
    putStrLn (show (option b "b"))
    putStr "option b \"a\"  = "
    putStrLn (show (option b "a"))
    putStrLn ""


--test for plus
test_plus = 
 do
    putStrLn "Testing function plus"
    putStr "plus a \"a\"  = "
    putStrLn (show (plus a "a"))
    putStr "plus a \"aa\"  = "
    putStrLn (show (plus a "aa"))
    putStr "plus a \"b\"  = "
    putStrLn (show (plus a "b"))
    putStr "plus b \"b\"  = "
    putStrLn (show (plus b "b"))
    putStr "plus b \"\"  = "
    putStrLn (show (plus b ""))
    putStrLn ""

--test nonZero


test_nonZero = 
	do
		putStrLn "Testing RegExp nonZero"
		putStr "nonZero \"0\"  = "
		putStrLn (show(nonZero "0"))
		putStr "nonZero \"1\"  = "
		putStrLn (show(nonZero "1"))
		putStr "nonZero \"01\"  = "
		putStrLn (show(nonZero "01"))
		putStr "nonZero \"10\"  = "
		putStrLn (show(nonZero "10"))
		putStr "nonZero \"1010\"  = "
		putStrLn (show(nonZero "1010"))
		putStr "nonZero \"101\"  = "
		putStrLn (show(nonZero "101"))
		putStr "nonZero \"0101\"  = "
		putStrLn (show(nonZero "0101"))
		putStr "nonZero \"\"  = "
		putStrLn (show(nonZero ""))
		putStr "nonZero \"1.5\"  = "
		putStrLn (show(nonZero "1.5"))
		putStr "nonZero \"a\"  = "
		putStrLn (show(nonZero "a"))
		putStrLn ""
    	
  -- test for fractNum
test_fractNum = 
	do
		putStrLn "Testing RegExp fractNum"
		putStr "fractNum \"1.1\"  = "
		putStrLn (show(fractNum "1.1"))
		putStr "fractNum \"1.0\"  = "
		putStrLn (show(fractNum "1.0"))
		putStr "fractNum \"0.1\"  = "
		putStrLn (show(fractNum "0.1"))
		putStr "fractNum \"11.1\"  = "
		putStrLn (show(fractNum "11.1"))
		putStr "fractNum \"1.11\"  = "
		putStrLn (show(fractNum "1.11"))
		putStr "fractNum \"111.1111\"  = "
		putStrLn (show(fractNum "111.1111"))
		putStr "fractNum \"\"  = "
		putStrLn (show(fractNum ""))
		putStr "fractNum \"101.101\"  = "
		putStrLn (show(fractNum "101.101"))
		putStrLn ""


--test for threeab
test_threeab = 
	do 
		putStrLn "Testing function threeab"
		putStr "threeab \"aaa\" = "
		putStrLn (show (threeab "aaa"))
		putStr "threeab \"aa\" = "
		putStrLn (show (threeab "aa"))
		putStr "threeab \"bbb\" = "
		putStrLn (show (threeab "bbb"))
		putStr "threeab \"bba\" = "
		putStrLn (show (threeab "bba"))
		putStr "threeab \"aaaa\" = "
		putStrLn (show (threeab "aaaa"))
		putStr "threeab \"\" = "
		putStrLn (show (threeab ""))
		putStr "threeab \"aabb\" = "
		putStrLn (show (threeab "aabb"))
		putStrLn ""


--test for exactlyTwoA
test_exactlyTwoA =
	do
		putStrLn "Testing function exactlyTwoA"
		putStr "exactlyTwoA \"a\" = "
		putStrLn (show (exactlyTwoA "a"))
		putStr "exactlyTwoA \"aa\" = "
		putStrLn (show (exactlyTwoA "aa"))
		putStr "exactlyTwoA \"aab\" = "
		putStrLn (show (exactlyTwoA "aab"))
		putStr "exactlyTwoA \"abab\" = "
		putStrLn (show (exactlyTwoA "abab"))
		putStr "exactlyTwoA \"abb\" = "
		putStrLn (show (exactlyTwoA "abb"))
		putStr "exactlyTwoA \"aaaa\" = "
		putStrLn (show (exactlyTwoA "aaaa"))
		putStr "exactlyTwoA \"ababa\" = "
		putStrLn (show (exactlyTwoA "ababa"))
		putStr "exactlyTwoA \"\" = "
		putStrLn (show (exactlyTwoA ""))
		putStr "exactlyTwoA \"baab\" = "
		putStrLn (show (exactlyTwoA "baab"))
		putStr "exactlyTwoA \"aabbbb\" = "
		putStrLn (show (exactlyTwoA "aabbbb"))
		putStr "exactlyTwoA \"bbbbbbbaa\" = "
		putStrLn (show (exactlyTwoA "bbbbbbbaa"))
		putStr "exactlyTwoA \"bbbbbbabbbbbba\" = "
		putStrLn (show (exactlyTwoA "bbbbbbabbbbbba"))
		putStrLn ""


-- run this to call all tests
test_all = 
	do
		test_option
		test_plus
		test_nonZero
		test_fractNum
		test_threeab
		test_exactlyTwoA
