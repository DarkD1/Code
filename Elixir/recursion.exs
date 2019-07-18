# TASK

# Recursion

defmodule Challenge do
  def main do
    words = ["Sazzad", "Hossain", "Shopno"]
    display(words)
    IO.puts "Factorial of 5 is #{factorial(5)}"
    IO.puts "10th fibonacci number is #{fib(10)}"
    IO.puts "Sum of 1..5 is #{sum([1,2,3,4,5])}"
  end

  def display([word|words]) do
    IO.puts word
    display(words)
  end

  def display([]), do: nil # Base Case

  def factorial(num) do
    if num <= 1 do
      1
    else
        num * factorial(num - 1)
    end
  end

  def fib(num) do
    cond do
      num == 1 -> 0
      num == 2 -> 1
      true -> fib(num - 1) + fib(num - 2)
    end
  end

  def sum([]), do: 0
  def sum([head | tail]), do: head + sum(tail)
end