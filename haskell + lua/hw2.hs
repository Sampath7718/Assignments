-- Eli Allen
-- CSCI 450 
-- Homework 2


-- Extended exercise: supermarket billing
-- ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

-- Types of names, prices (pence) and bar-codes.

type Name    = String
type Price   = Int
type BarCode = Int

-- The database linking names prices and bar codes.

type Database = [ (BarCode,Name,Price) ]

-- The example database we use is

codeIndex :: Database
codeIndex = [ (4719, "Fish Fingers" , 121),
              (5643, "Nappies" , 1010),
              (3814, "Orange Jelly", 56),
              (1111, "Hula Hoops", 21),
              (1112, "Hula Hoops (Giant)", 133),
              (1234, "Dry Sherry, 1lt", 540)]

-- The lists of bar codes, and of Name,Price pairs.

type TillType = [BarCode]
type BillType = [(Name,Price)]

-- The length of a line in the bill.

lineLength :: Int
lineLength = 30

-- 6.39: takes a price that represents cents and returns a string that represents dollars
formatCents :: Price -> String
formatCents x | x `mod` 100 >= 10 = show(x `div` 100) ++ "." ++ show(x `mod` 100)
			  | x `mod` 100 < 10  = show(x `div` 100) ++ ".0" ++ show(x `mod` 100)

-- test function for formatCents --	
test_formatCents = 
  do 
	putStr "formatCents 1234 = "
	putStrLn (show (formatCents 1234))
	putStr "formatCents 12 = "
	putStrLn (show (formatCents 12))
	putStr "formatCents 10 = "
	putStrLn (show (formatCents 10))
	putStr "formatCents 1001 = "
	putStrLn (show (formatCents 1001))
	putStr "formatCents 0 = "
	putStrLn (show (formatCents 0))
	putStr "formatCents 0000 = "
	putStrLn (show (formatCents 0000))
	putStr "formatCents 00 = "
	putStrLn (show (formatCents 00))
	
	
-- 6.40: takes a name and price and returns the formatted line of a bill
formatLine :: (Name, Price) -> String
formatLine (x, y) = x ++ replicate (lineLength - length x - length y') '.' ++ y'
                    where y' = formatCents y
-- test function for formatLine			
test_formatLine = 
  do 
	putStr "formatLine (Smithy, 1234) = "
	putStrLn (show (formatLine ("Smithy", 1234)))
	putStr "formatLine ('NAME', 12) = "
	putStrLn (show (formatLine ("NAME", 12)))
	putStr "formatLine ('Lastname', 1234) = "
	putStrLn (show (formatLine ("Lastname", 0101)))
	
	
-- 6.41: Takes a list of (name, price) and returns them all as one string
-- *Note that the function could also accept BillType as the argument, but the instructions asked for it this way
formatLines :: [ (Name, Price) ] -> String
formatLines [] = []
formatLines (x:xs) = formatLine x ++ "   \n" ++ formatLines xs   

-- test function for formatLines
test_formatLines = 
  do 
	putStrLn "formatLines [('Dry Sherry, 1lt', 540), ('Fish Fingers', 121), ('Orange jelly', 56)] = "
	putStrLn ( (formatLines [("Dry Sherry", 540), ("Fish Fingers", 121), ("Orange jelly", 56)]))
	putStrLn "formatLines [('Dry Sherry, 1lt', 540)] = "
	putStrLn ( (formatLines [("Dry Sherry", 540)]))
	putStrLn "formatLines [] = "
	putStrLn ( (formatLines []))
	
	
	
-- 6.42: takes a list of "bills" and returns the sum of the prices
makeTotal :: BillType -> Price
makeTotal (x:xs) = toPrice x + makeTotal xs
makeTotal [] = 0


-- toPrice is an auxilery function I made for makeTotal. I probably could have used prelude sum
toPrice :: (Name, Price) -> Price
toPrice (x, y) = y


-- test function for makeTotal		
test_makeTotal = 
  do 
	putStrLn "makeTotal [('Dry Sherry, 1lt', 540), ('Fish Fingers', 121), ('Orange jelly', 56)] = "
	putStrLn (show (makeTotal [("Dry Sherry", 540), ("Fish Fingers", 121), ("Orange jelly", 56)]))
	putStrLn "makeTotal [('Dry Sherry, 1lt', 540), ('Fish Fingers', 121)] = "
	putStrLn (show (makeTotal [("Dry Sherry", 540), ("Fish Fingers", 121)]))
	putStrLn "makeTotal [('Dry Sherry, 1lt', 540)] = "
	putStrLn (show (makeTotal [("Dry Sherry", 540)]))
	putStrLn "makeTotal [] = "
	putStrLn (show (makeTotal []))

-- 6.43: takes a price and formats it with formatLine (I still don't know why the instructions want all those dots)
formatTotal :: Price -> String
formatTotal x = formatLine ("Total", x)

-- test function for formatTotal			
test_formatTotal = 
  do 
	putStrLn "formatTotal 3 = "
	putStrLn ( (formatTotal 3012))
	putStrLn "formatTotal 10 = "
	putStrLn ( (formatTotal 10))
	putStrLn "formatTotal 0 = "
	putStrLn ( (formatTotal 0))

-- 6.44: takes a BillType and returns a nice and neat string(Now I understand the need for dots)
formatBill :: BillType -> String
formatBill x = formatLines x ++  formatTotal(makeTotal x)

-- test function for formatBill		
test_formatBill = 
  do 
	putStrLn "formatBill [('Dry Sherry, 1lt', 540), ('Fish Fingers', 121), ('Orange jelly', 56)] = "
	putStrLn (formatBill [("Dry Sherry", 540), ("Fish Fingers", 121), ("Orange jelly", 56)])
	putStrLn "formatBill [('Dry Sherry, 1lt', 540), ('Fish Fingers', 121)] = "
	putStrLn ( (formatBill [("Dry Sherry", 540), ("Fish Fingers", 121)]))
	putStrLn "formatBill [('Dry Sherry, 1lt', 540)] = "
	putStrLn ( (formatBill [("Dry Sherry", 540)]))
	putStrLn "formatBill [] = "
	putStr ( (formatBill []))

-- 6.45: takes a database and barcode and returns one (name, price) pair that is found in the database
--      The instructions say that I can assume there are no repeat values in the database
look :: Database -> BarCode -> (Name, Price)
look db code | length found == 1 = head found
			 | length found == 0 = ("Unknown item", 0)
					  where found = [(x, y) | (code', x, y) <- db, code' == code]

-- test function for look			
test_look = 
  do 
	putStrLn "look codeIndex 4719 = "
	putStrLn (show (look codeIndex 4719))
	putStrLn "look codeIndex 5643 = "
	putStrLn (show (look codeIndex 5643))
	putStrLn "look codeIndex 0 = "
	putStrLn (show (look codeIndex 0))
					  
-- 6.46: takes a barcode object to look up in the database. It provides a nice layer of abstraction so that we don't have to know the name of the database when running the function		\
--       The function is named lookup' to avoid conflict with the prelude function
lookup' :: BarCode -> (Name, Price)
lookup' x = look codeIndex x		

-- test function for lookup'			
test_lookup' = 
  do 
	putStrLn "lookup' 4719 = "
	putStrLn (show (lookup' 4719))
	putStrLn "lookup' 5643 = "
	putStrLn (show (lookup' 5643))
	putStrLn "lookup' 0 = "
	putStrLn (show (lookup' 0))

-- 6.47: Takes an input list, looks up each barcode, and outputs lists of what is found in the database. 
makeBill :: TillType -> BillType
makeBill x = [lookup' y | y <-x]

-- test function for makeBill			
test_makeBill = 
  do 
	putStrLn "makeBill [1234, 4719, 3814, 1112, 1113, 1234] = "
	putStrLn (show (makeBill [1234, 4719, 3814, 1112, 1113, 1234]))
	putStrLn "makeBill [1234, 4719, 3814] = "
	putStrLn (show (makeBill [1234, 4719, 3814]))
	putStrLn "makeBill [1234, 3814, 1112, 1113] = "
	putStrLn (show (makeBill [1234, 3814, 1112, 1113]))
	
	


