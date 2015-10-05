-- Eli Allen --
-- CSCI 450 --
-- Assignment 1 --

-- 5.7 excercises --


-- 1: xor --

-- takes two Bools and returns a Bool --
xor :: Bool -> Bool -> Bool 
xor a b = (a || b) && not (a && b) -- result is true if a or b is true, but not in the case where a and b are true


-- test function for xor --
test_xor = 
  do
     putStr "xor True  True  = "
     putStrLn (show (xor True True))
     putStr "Success:  "
     putStrLn (show (xor True True == False))
     putStr "xor True  False = "
     putStrLn (show (xor True False))
     putStr "Success:  "
     putStrLn (show (xor True False == True))
     putStr "xor False True  = "
     putStrLn (show (xor False True))
     putStr "Success:  "
     putStrLn (show (xor False True == True))
     putStr "xor False False = "   
     putStrLn (show (xor False False))
     putStr "Success:  "
     putStrLn (show (xor False False == False))
     

-- 2: mult -- 

-- takes 2 ints and returns their product without using * or / operators --
mult :: Int -> Int -> Int
mult a 1 = a  -- if the second argument is 1, the product is a --
mult a b = mult a (b-1) + a  -- recursively call mult with arguments a and b-1 until the b argument is 1
	

-- test function for mult --	
test_mult = 
  do 
	putStr "mult 1 1 = "
	putStrLn (show (mult 1 1))
	putStr "mult 2 1 = "
	putStrLn (show (mult 2 1))
	putStr "mult 2 2 = "
	putStrLn (show (mult 2 2))
	putStr "mult 2 5 = "
	putStrLn (show (mult 2 5))
	putStr "mult 3 6 = "
	putStrLn (show (mult 3 6))
	

-- 3: max List value (maxLval) --

-- takes a list of ints and returns the maximum --
maxLval :: [Int] -> Int
maxLval (a : b : as)
	| a >= b = maxLval (a : as)
	| a < b = maxLval (b : as)
maxLval (a : as) = a


-- test function for maxLval
test_maxLval = 
  do 
	putStr "maxLval [1, 1, 2] = "
	putStrLn (show (maxLval [1, 1, 2]))
	putStr "maxLval [1, 0, 0] = "
	putStrLn (show (maxLval [1, 0, 0]))
	putStr "maxLval [-1, -2, 3] = "
	putStrLn (show (maxLval [-1, -2, 3]))
	putStr "maxLval [99, 3, 22] = "
	putStrLn (show (maxLval [99, 3, 22]))

-- 4: adjpairs --

adjpairs :: [Integer] -> [(Integer, Integer)]
adjpairs (a : b : as) = (a, b) : adjpairs(b : as)
adjpairs (a: as) = []

--test function for adjpairs --

test_adjpairs = 
  do 
	putStr "adjpairs [1, 1, 2] = "
	putStrLn (show (adjpairs [1, 1, 2]))
	putStr "adjpairs [1, 2, 3, 4] = "
	putStrLn (show (adjpairs [1, 2, 3, 4]))
	putStr "adjpairs [ 1, 2] = "
	putStrLn (show (adjpairs [ 1, 2]))
	putStr "adjpairs [1] = "
	putStrLn (show (adjpairs [1]))

-- 5: mean --


--takes a list of ints and returns their mean (truncates fractions)

mean :: [Int] -> Int
mean a = (total a) `quot` (size a) -- uses functions total and size as defined below for the mean equation


-- calculates sum of list of ints --

total :: [Int] -> Int 
total (a : as) = a + total as -- add each value to the last --
total as = 0

-- calculates size of a list --

size :: [Int] -> Int
size (a : as ) = 1 + size as --add 1 for each member of the list --
size as = 0

--test for mean --
test_mean =
  do
	putStr "mean [1, 1, 2] = "
	putStrLn (show (mean [1, 1, 2]))
	putStr "mean [55, 1001] = "
	putStrLn (show (mean [55, 1001]))
	putStr "mean [0, 0, 0, 20] = "
	putStrLn (show (mean [0, 0, 0, 20]))
	putStr "mean [7, 9, 11] = "
	putStrLn (show (mean [7, 9, 11]))
	putStr "mean [0, 0, 1] = "
	putStrLn (show (mean [0, 0, 1]))




-- 7a: natToBin --

-- takes a natural number and returns the binary representation of that number with the most significant digit at the head --

natToBin :: Int -> [Int]
natToBin 0 = [0] -- if the number is 0 then so is the binary number --
natToBin 1 = [1] -- if the number is 1, so is the binary
natToBin a
    | a `mod` 2 == 0 = natToBin (a `quot` 2) ++ [0] -- if remainder of a and 2 is 0, append a 0 to the list and make a recursive call to natToBin using the quotient a and 2 --
    | otherwise = natToBin (a `quot` 2) ++ [1] -- if remainder is 1, make a recursive call and append a 1 to the list --


-- test for natToBin --
test_natToBin = 
  do
	putStr "natToBin 1 = "
	putStrLn (show (natToBin 1))
	putStr "natToBin 2 = "
	putStrLn (show (natToBin 2))
	putStr "natToBin 3 = "
	putStrLn (show (natToBin 3))
	putStr "natToBin 6 = "
	putStrLn (show (natToBin 6))
	putStr "natToBin 11 = "
	putStrLn (show (natToBin 11))
	putStr "natToBin 120 = "
	putStrLn (show (natToBin 121))
	putStr "natToBin 10000001 = "
	putStrLn (show (natToBin 10000001))
	




