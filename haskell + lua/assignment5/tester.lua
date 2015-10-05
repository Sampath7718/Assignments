x=3
function g(z)
  return x+z 
end

function f(y) 
 local  x = y+1
    return g(y*x)
end

print("result " .. f(3))
