--[[ Arithmetic Expression Tree Program Skeleton
     Recursive Function Version with Record-style Nodes
     H. Conrad Cunningham, Professor
     Computer and Information Science
     University of Mississippi
SUCK IT! YOU SUCK! HAHAHAHHAHAHA I HATE YOU AND YOUR STUPID LANGUAGES!!!!
Developed for CSci 658, Software Language Engineering, Fall 2013

1234567890123456789012345678901234567890123456789012345678901234567890

2013-09-03: Modified Recursive Function List-node and Object-based
            versions to create this version
2013-09-07: Changed "type" field of table to be "tag"
2014-11-11: Corrected typo, added isExp structure checking function,
            and restructured similar to newest Recursive Function
            List version
--]]


--[[ ARITHMETIC EXPRESSION TREES

This program represents an arithmetic expression tree by a
record-style table with a type tag field and one or more named 
fields to hold the operands.

--]]

-- Constants for tree node type tags
local SUM_TYPE,   SUM_STR   = "Sum", "Sum"
local SUB_TYPE,   SUB_STR   = "Sub", "Sub"
local PROD_TYPE,  PROD_STR  = "Prod", "Prod"
local DIV_TYPE,   DIV_STR   = "Div", "Div"
local NEG_TYPE,   NEG_STR   = "Neg", "Neg"
local COS_TYPE,   COS_STR   = "Cos", "Cos"
local SIN_TYPE,   SIN_STR   = "Sin", "Sin"
local VAR_TYPE,   VAR_STR   = "Var", "Var"
local CONST_TYPE, CONST_STR = "Const", "Const"
-- Checking for valid expressions

local tags = { [CONST_TYPE] = true, [VAR_TYPE] = true, 
               [SUM_TYPE]   = true                     }

local function isExp(t)
  return type(t) == "table" and t.tag ~= nil
end
    
-- Tree node constructor functions

local function makeConst(v)
  if type(v) == "number" then 
    return { tag = CONST_TYPE, value = v }
  else
    error("makeConst called with nonumeric value field: " .. 
          tostring(v), 2)
  end
end

local function makeVar(n)
  if type(n) == "string" then
    return { tag = VAR_TYPE, name = n }
  else
    error("makeVar called with nonstring name argument: " .. 
          tostring(n), 2)
  end
end

local function makeSum(l,r)
  if isExp(l) then
    if isExp(r) then
      return { tag = SUM_TYPE, left = l, right = r }
    else
      error("Second argument of makeSum is not a valid expression: " 
            .. tostring(r), 2)
    end
  else
    error("First argument of makeSum is not a valid expression: " ..
          tostring(l), 2)
  end
end

local function makeSub(l,r)
  if isExp(l) then
    if isExp(r) then
      return { tag = SUB_TYPE, left = l, right = r }
    else
      error("Second argument of makeSub is not a valid expression: " 
            .. tostring(r), 2)
    end
  else
    error("First argument of makeSub is not a valid expression: " ..
          tostring(l), 2)
  end
end

local function makeProd(l,r)
  if isExp(l) then
    if isExp(r) then
      return { tag = PROD_TYPE, left = l, right = r }
    else
      error("Second argument of makeProd is not a valid expression: " 
            .. tostring(r), 2)
    end
  else
    error("First argument of makeProd is not a valid expression: " ..
          tostring(l), 2)
  end
end

local function makeDiv(l,r)
  if isExp(l) then
    if isExp(r) then
      return { tag = DIV_TYPE, left = l, right = r }
    else
      error("Second argument of makeDiv is not a valid expression: " 
            .. tostring(r), 2)
    end
  else
    error("First argument of makeDIV is not a valid expression: " ..
          tostring(l), 2)
  end
end

local function makeNeg(v)
  if isExp(v) then 
    return { tag = NEG_TYPE, value = v}
  else
    error("makeNeg called with nonumeric value field: " .. 
          tostring(v), 2)
  end
end

local function makeSin(v)
  if isExp(v) then 
    return { tag = SIN_TYPE, value = v}
  else
    error("makeSin called with nonumeric value field: " .. 
          tostring(v), 2)
  end
end

local function makeCos(v)
  if isExp(v) then 
    return { tag = COS_TYPE, value = v}
  else
    error("makeCos called with nonumeric value field: " .. 
          tostring(v), 2)
  end
end
-- Constant tree node singletons
local CONST_ZERO = makeConst(0)
local CONST_ONE  = makeConst(1)

-- Function "eval" evaluates expression tree "t" in environment
-- "env". It checks the operator (first element of "t") to determine
-- what actions to take.

local function eval(t,env)
  if isExp(t) then
    if type(env) == "table" then
      if t.tag == SUM_TYPE then 
        return eval(t.left,env) + eval(t.right,env)
      elseif t.tag == VAR_TYPE then
        return env[t.name]
      elseif t.tag == CONST_TYPE then
        return t.value
	  elseif t.tag == SUB_TYPE then 
		return eval(t.left,env) - eval(t.right,env) 
	  elseif t.tag == DIV_TYPE then
	    return eval(t.left,env) / eval(t.right,env)
	  elseif t.tag == PROD_TYPE then
		return eval(t.left,env) * eval(t.right,env)
	  elseif t.tag == NEG_TYPE then
		return t.value
	  elseif t.tag == SIN_TYPE then
		return math.sin(eval(t.value, env))
	  elseif t.tag == COS_TYPE then
		return math.cos(eval(t.value, env))
      else
        error("eval called with unknown tree type tag: " .. 
              tostring(t.tag), 2)
      end
    else
      error("eval called with invalid environment argument: " .. 
            tostring(env), 2)
    end
  else
    error("eval called with invalid expression argument: " .. 
          tostring(t), 2)
  end
end

-- Function "derive" takes an arithmetic expression tree "t" and a
-- variable "v" and returns the derivative, another arithmetic
-- expression tree.

local function derive(t,v)
  if isExp(t) then
    if type(v) == "string" then
      if t.tag == SUM_TYPE then
        return makeSum(derive(t.left,v), derive(t.right,v))
	  elseif t.tag == SUB_TYPE then
		return makeSum(derive(t.left,v), derive(t.right,v))
	  elseif t.tag == NEG_TYPE then
		return derive(t.value)
	  elseif t.tag == PROD_TYPE then
		return makeSum(makeProd(t.left, derive(t.right,v)), makeProd(t.right, derive(t.left,v)))
	  elseif t.tag == DIV_TYPE then
		return makeDiv(makeSub(makeProd(t.left, derive(t.right,v)), makeProd(t.right, derive(t.left,v))), makeProd(t.left, t.left))
	  elseif t.tag == SIN_TYPE then
		return makeProd(makeCos(t.value), derive(t.value, v))
	  elseif t.tag == COS_TYPE then
		return makeNeg(makeProd(makeSin(t.value)), derive(t.value, v))
      elseif t.tag == VAR_TYPE then
        if v == t.name then     
          return CONST_ONE
        else
          return CONST_ZERO
        end
      elseif t.tag == CONST_TYPE then
        return CONST_ZERO
      else
        error("derive called with unknown tree type tag: " .. 
              tostring(t.tag), 2)
      end
    else
      error("derive called with invalid variable: " .. 
            tostring(v), 2)
    end
  else
    error("derive called with invalid expression argument: " ..
          tostring(t), 2)
  end
end

-- Function "valToString" takes an arithmetic expression tree "t" and
-- returns a string representation of the expression tree.

local function valToString(t)
  if isExp(t) then
    if t.tag == SUM_TYPE then 
      return SUM_STR .. "(" .. valToString(t.left)  .. "," 
                            .. valToString(t.right) .. ")"
	elseif t.tag == SUB_TYPE then
		return SUB_STR .. "(" .. valToString(t.left) .. ","
					          .. valToString(t.right) ..")"
	elseif t.tag == PROD_TYPE then
		return PROD_STR .. "(" .. valToString(t.left) .. ","
					           .. valToString(t.right) ..")"
	elseif t.tag == DIV_TYPE then
		return DIV_STR .. "(" .. valToString(t.left) .. ","
					          .. valToString(t.right) ..")"	
	elseif t.tag == SIN_TYPE then
      return SIN_STR .. "(" .. valToString(t.value) .. ")"	
	elseif t.tag == COS_TYPE then
      return SIN_STR .. "(" .. valToString(t.value) .. ")"	
    elseif t.tag == VAR_TYPE then
      return VAR_STR .. "(" .. t.name .. ")"
    elseif t.tag == CONST_TYPE then
      return CONST_STR .. "(" .. tostring(t.value) .. ")"
    elseif t.tag == NEG_TYPE then
	  return NEG_STR .. "(" .. valToString(t.value) .. ")"
	else
      error("valToString called with unknown tree type tag: " ..
            tostring(t.tag), 2)
    end
  else
    error("valToString called with invalid expression: " ..
          tostring(t), 2)
  end
end

local function simplify(t)
	if isExp(t) then
	 if t.left then t.left = simplify(t.left)
	 elseif t.right then t.right = simplify(t.right)
	 elseif t.exp then t.exp = simplify(t.exp)
		if t.left.tag == CONST_TYPE and t.right.tag == CONST_TYPE or t.exp.tag == CONST_TYPE then 
		return makeConst(eval(t,{}))
		end
	 end
	else return t
	end
end
-- MAIN PROGRAM
--to test other values, simply rearrange the numbers
--test makeSum
local exp = makeSum( makeSum(makeVar("x"),makeVar("x")), 
                     makeSum(makeConst(7),makeVar("y")) )
local env = { x = 5, y = 7 }

print("Expression: " .. valToString(exp))
print("Evaluation with x=5, y=7: " .. eval(exp,env))
print("Derivative relative to x:\n  " .. 
      valToString(derive(exp, "x")))
print("Derivative relative to y:\n  " .. 
      valToString(derive(exp, "y")))
	  
--test makeSub
local exp = makeSub(makeVar("x"),makeVar("y"))
local env = { x = 9, y = 7 }

print("Expression: " .. valToString(exp))
print("Evaluation with x=9, y=7: " .. eval(exp,env))
print("Derivative relative to x:\n  " .. 
      valToString(derive(exp, "x")))
print("Derivative relative to y:\n  " .. 
      valToString(derive(exp, "y")))
	  
--test makeProd
local exp = makeProd(makeVar("x"), makeVar("y"))
local env = { x = 2, y = 3 }

print("Expression: " .. valToString(exp))
print("Evaluation with x=2, y=3: " .. eval(exp,env))
print("Derivative relative to x:\n  " .. 
      valToString(derive(exp, "x")))
print("Derivative relative to y:\n  " .. 
      valToString(derive(exp, "y")))
	  
--test makeDiv
local exp = makeDiv(makeVar("x"),makeVar("y"))
local env = { x = 4, y = 2 }

print("Expression: " .. valToString(exp))
print("Evaluation with x=4, y=2: " .. eval(exp,env))
print("Derivative relative to x:\n  " .. 
      valToString(derive(exp, "x")))
print("Derivative relative to y:\n  " .. 
      valToString(derive(exp, "y")))
	  
--test makeSin
local exp = makeSin(makeConst(90))
local env = {}
print("Expression: " .. valToString(exp))
print("Evaluation: " .. eval(exp,env))


--test makeCos
local exp = makeCos(makeConst(180))
local env = {}
print("Expression: " .. valToString(exp))
print("Evaluation: " .. eval(exp,env))

	  

	  
	  
	  
