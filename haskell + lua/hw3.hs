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
-- epsilon ||| (p <*> star p)
-- is OK as long as p can't have epsilon match

fsplits :: String -> [(String,String)]
fsplits xs = tail (splits xs)

-- define a few char patterns for use in exercises
a,b :: RegExp
a = char 'a'
b = char 'b'

--- End of base program for assignment