# TASK

# Return the number (count) of vowels in the given string.

defmodule Challenge do
  def main do
    get_count("aeiou")
  end
  def get_count(str) do
    str |> String.graphemes |> Enum.count(fn c -> c == "a" or c == "e" or c == "i" or c == "o" or c == "u" end)
  end
end
