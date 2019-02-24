# TASK

# Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.

defmodule Challenge do
  def main do
    even_or_odd(10)
  end
  def even_or_odd(number) do
    if rem(number, 2) == 0, do: "Even", else: "Odd" 
  end
end