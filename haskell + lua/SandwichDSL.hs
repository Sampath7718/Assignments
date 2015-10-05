{- CSci 450/503, Fall 2014
   Homework #4: Sandwich DSL
   Eli Allen
   7 November 2014

1234567890123456789012345678901234567890123456789012345678901234567890

This is the SandwichDSL base code from the case study. It can be
expanded to build the module for Assignment #4.

-}

module SandwichDSL
where

-- Used functions from these modules in my implementation
import Data.Maybe
import Data.List

{- Haskell data type definitions from "Building the DSL" -}

data Platter   = Platter [Sandwich] 
                 deriving Show

data Sandwich  = Sandwich [Layer]
                 deriving Show

data Layer     = Bread Bread         | Meat Meat           |
                 Cheese Cheese       | Vegetable Vegetable | 
                 Condiment Condiment
                 deriving (Eq,Show)

data Bread     = White | Wheat | Rye
                 deriving (Eq,Show)

data Meat      = Turkey | Chicken | Ham | RoastBeef | Tofu
                 deriving (Eq,Show)

data Cheese    = American | Swiss | Jack | Cheddar
                 deriving (Eq,Show)

data Vegetable = Tomato | Onion | Lettuce | BellPepper
                 deriving (Eq,Show)

data Condiment = Mayo | Mustard | Ketchup | Relish | Tabasco
                 deriving (Eq,Show)
				 
data SandwichOp = StartSandwich   		 | FinishSandwich  		  |
                  AddBread Bread   		 | AddMeat Meat   		  |
                  AddCheese Cheese 		 | AddVegetable Vegetable | 
                  AddCondiment Condiment |
                  StartPlatter 			 | MoveToPlatter 		  | FinishPlatter 
                  deriving (Eq, Show) 

data Program = Program [SandwichOp]
               deriving Show

prices = [(Bread White,20),(Bread Wheat,30),(Bread Rye,30), 
          (Meat Turkey,100),(Meat Chicken,80),(Meat Ham,120),
          (Meat RoastBeef,140),(Meat Tofu,50),
          (Cheese American,50),(Cheese Swiss,60),
          (Cheese Jack,60),(Cheese Cheddar,60),
          (Vegetable Tomato,25),(Vegetable Onion,20),
          (Vegetable Lettuce,20),(Vegetable BellPepper,25),
          (Condiment Mayo,5),(Condiment Mustard,4),
          (Condiment Ketchup,4),(Condiment Relish,10),
          (Condiment Tabasco,5) 
         ]
--Exercise set 1: 

--1. 
newSandwich :: Bread -> Sandwich
newSandwich b = Sandwich[Bread b]

--test for newSandwich
test_newSandwich = 
  do
    putStrLn "Testing function newSandwich"
    putStr "newSandwich White = "
    putStrLn (show (newSandwich White))
    putStr "newSandwich Rye = "
    putStrLn (show (newSandwich Rye))	
    putStr "newSandwich Wheat = "
    putStrLn (show (newSandwich Wheat))
    putStrLn ""

addLayer :: Sandwich -> Layer -> Sandwich
addLayer (Sandwich s) l = Sandwich(l:s) 

--test for addLayer
test_addLayer = 
  do
    putStrLn "Testing function addLayer"
    putStr "addLayer (Sandwich[Bread White]) (Bread White) = "
    putStrLn (show (addLayer (Sandwich[Bread White]) (Bread White)))
    putStr "addLayer (Sandwich[Cheese Jack]) (Bread White) = "
    putStrLn (show (addLayer (Sandwich[Cheese Jack]) (Bread White)))
    putStr "addLayer (Sandwich[Bread White, Vegetable BellPepper, Condiment Mayo]) (Bread Rye) = "
    putStrLn (show (addLayer (Sandwich[Bread White, Vegetable BellPepper, Condiment Mayo]) (Bread Rye)))



newPlatter ::  Platter
newPlatter = Platter[]

--test for newPlatter
test_newPlatter = 
  do
    putStrLn "Testing function newPlatter"
    putStr "newPlatter = "
    putStrLn (show (newPlatter))

addSandwich :: Platter -> Sandwich -> Platter
addSandwich (Platter p) s = Platter(s:p)

--test for addSandwich
test_addSandwich = 
  do
    putStrLn "Testing function addSandwich"
    putStr "addSandwich (Platter[Sandwich[]]) (Sandwich[Bread White]) ="
    putStrLn (show (addSandwich (Platter[Sandwich[]]) (Sandwich[Bread White])))
    putStr "addSandwich (Platter[Sandwich[], Sandwich[Cheese Jack, Vegetable BellPepper]]) (Sandwich[Bread White]) ="
    putStrLn (show (addSandwich (Platter[Sandwich[], Sandwich[Cheese Jack, Vegetable BellPepper]]) (Sandwich[Bread White])))
    putStr "addSandwich (Platter[]) (Sandwich[]) ="
    putStrLn (show (addSandwich (Platter[]) (Sandwich[])))
    

--2. 
isBread :: Layer -> Bool
isBread (Bread b) = True
isBread _ = False

--test function for isBread. Because the other 'is' methods are nearly identical, this is the only test I wrote
test_isBread = 
  do
    putStrLn "Testing function isBread."
    putStr " isBread (Bread White) ="
    putStrLn (show (isBread(Bread White)))
    putStr " isBread (Bread Rye) ="
    putStrLn (show (isBread(Bread Rye)))
    putStr " isBread (Vegetable BellPepper) ="
    putStrLn (show (isBread(Vegetable BellPepper)))

isMeat :: Layer -> Bool
isMeat(Meat m) = True
isMeat _ = False

isCheese :: Layer -> Bool
isCheese (Cheese c) = True
isCheese _ = False

isVegetable :: Layer -> Bool
isVegetable (Vegetable v) = True
isVegetable _ = False

isCondiment :: Layer -> Bool
isCondiment (Condiment c) = True
isCondiment _ = False

--3. 
noMeat :: Sandwich -> Bool
noMeat (Sandwich s) = filter isMeat s == []

--test for noMeat
test_noMeat = 
  do
    putStrLn "Tesing function noMeat"
    putStr "noMeat (Sandwich[Bread White, Vegetable BellPepper]) ="
    putStrLn (show (noMeat(Sandwich[Bread White, Vegetable BellPepper])))
    putStr "noMeat (Sandwich[Bread White, Meat RoastBeef]) ="
    putStrLn (show (noMeat(Sandwich[Bread White, Meat RoastBeef])))
    
--4. 
--inOSO


--5. 	
priceSandwich :: Sandwich -> Int
priceSandwich (Sandwich (l)) = sum[getPrice(lookup layer prices) | layer <- l]

getPrice :: (Maybe Int) -> Int
getPrice (Just x) = x
getPrice _ =0

test_priceSandwich = 
  do
    putStrLn "Tesing function priceSandwich"
    putStr "priceSandwich (Sandwich[Bread White, Vegetable BellPepper]) ="
    putStrLn (show (priceSandwich(Sandwich[Bread White, Vegetable BellPepper])))
    putStr "priceSandwich (Sandwich[Bread White, Vegetable BellPepper, Cheese Jack]) ="
    putStrLn (show (priceSandwich(Sandwich[Bread White, Vegetable BellPepper, Cheese Jack])))
    putStr "priceSandwich (Sandwich[]) ="
    putStrLn (show (priceSandwich(Sandwich[])))
    
--6.
eqSandwich :: Sandwich -> Sandwich -> Bool
eqSandwich (Sandwich s1) (Sandwich s2) = (s1 `intersect` s2) == s1

test_eqSandwich = 
  do
    putStrLn "Tesing function eqSandwich"
    putStr "  putStrLn (show (eqSandwich (Sandwich[Bread White]) (Sandwich[Bread White])))="
    putStrLn (show (eqSandwich (Sandwich[Bread White]) (Sandwich[Bread White])))
    putStr "  putStrLn (show (eqSandwich (Sandwich[Bread White]) (Sandwich[Bread White])))="
    putStrLn (show (eqSandwich (Sandwich[Bread White]) (Sandwich[Bread Wheat])))

--Exercise 2

{- Haskell data type definitions from 
   "Compiling the Program for the SueChef Controller"
-}

			   
--1. 
compileSandwich :: Sandwich -> [SandwichOp]
compileSandwich s = [StartSandwich]++ (compileSandwichHelper s) ++ [FinishSandwich] 

compileSandwichHelper :: Sandwich -> [SandwichOp]
compileSandwichHelper (Sandwich(Bread b: bs)) = [(AddBread b)] ++ (compileSandwichHelper (Sandwich bs))
compileSandwichHelper(Sandwich(Meat m: ms)) = [(AddMeat m)] ++ (compileSandwichHelper (Sandwich ms))
compileSandwichHelper (Sandwich(Cheese c: cs)) = [(AddCheese c)] ++ (compileSandwichHelper (Sandwich cs))
compileSandwichHelper (Sandwich(Vegetable v: vs)) = [(AddVegetable v)] ++ (compileSandwichHelper (Sandwich vs))
compileSandwichHelper (Sandwich(Condiment cm: cms)) = [(AddCondiment cm)] ++ (compileSandwichHelper (Sandwich cms))
compileSandwichHelper _ = []

test_compileSandwich =
  do
    putStrLn "Tesing function compileSandwich"
    putStr "  putStrLn (show (compileSandwich (Sandwich[Bread White])="
    putStrLn (show (compileSandwich(Sandwich[Bread White])))
    putStr "  putStrLn (show (compileSandwich (Sandwich[Bread White, Cheese Jack])="
    putStrLn (show (compileSandwich(Sandwich[Bread White, Cheese Jack])))

--2. 
compile:: Platter -> Program
compile p = Program([StartPlatter] ++ compileHelper p ++ [FinishPlatter])

compileHelper :: Platter -> [SandwichOp]
compileHelper (Platter(p:ps)) =  compileSandwich p ++[MoveToPlatter] ++ (compileHelper (Platter ps)) 
compileHelper _ = []

test_compile =
  do
    putStrLn "Tesing function compile"
    putStr "  putStrLn (show (compile (Platter[Sandwich[Bread White], Sandwich [Bread White, Bread Rye, Cheese Jack])="
    putStrLn (show (compile (Platter[Sandwich[Bread White], Sandwich [Bread White, Bread Rye, Cheese Jack]])))
    putStr "  putStrLn (show (compile (Platter[Sandwich[Bread White], Sandwich [Bread White, Bread Rye, Cheese Jack], Sandwich[Vegetable BellPepper]])="
    putStrLn (show (compile (Platter[Sandwich[Bread White], Sandwich [Bread White, Bread Rye, Cheese Jack], Sandwich[Vegetable BellPepper]])))
    putStr "  putStrLn (show (compile (Platter[])="
    putStrLn (show (compile ((Platter[]))))

