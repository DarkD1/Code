# TASK

# Anonymous Function

defmodule Challenge do
  def main do
  	add = fn x, y -> x + y end
  	sub = fn x, y -> x - y end
  	IO.puts add.(10,5)
  	IO.puts sub.(10,5)
  	mul = &(&1 * &2)
  	div = &(&1 / &2)
  	IO.puts mul.(5, 6)
  	IO.puts div.(5, 6)

  	# if two argument then add two items, if three argument then add first two items then subtract by third item
  	magic = fn 
  		{a, b} ->  a + b
  		{a, b, c} -> a + b - c
  	end
  	IO.puts magic.({1,2})
  	IO.puts magic.({5,2,3})
  	IO.puts default_arg()
  	IO.puts default_arg(1)
  	IO.puts default_arg(100,100)
  end

  def default_arg(x \\ 5, y \\ 5) do # default argument \\
  	x + y
  end
end