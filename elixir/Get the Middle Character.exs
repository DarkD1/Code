# TASK

# You are going to be given a word. Your job is to return the middle character of the word.
# If the word's length is odd, return the middle character. If the word's length is even, return the middle 2 characters.

defmodule Challenge do
  def main do
    get_middle(10)
  end

  def get_middle(str) do 
    len = String.length(str)
    pos = Kernel.trunc(len / 2)
    if rem(len, 2) == 1, do: String.at(str, pos), else: String.at(str, pos-1) <> String.at(str, pos)
  end

end