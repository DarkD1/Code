# TASK

# Tuples

defmodule Challenge do
  def main do
  	list = {1,2,3} # index 0, 1, 2
    list2 = Tuple.append(list, 4) # appends an element at the end of list but to make any changes in list we need to store it in anohter list
    
    IO.puts "Element at index 3: #{elem(list2, 3)}" # retriving data from list at index 3
    IO.puts "Size of Tuple: #{tuple_size(list2)}" # size of tuple

    list3 = Tuple.delete_at(list2, 0) # deleting an element from list which is at index 0
    list4 = Tuple.insert_at(list3, 0, 81) # inserting an element into list at index 0 value 81
    {name, semester, roll} = {"Sazzad", "4th", 17081} # Pattern matching
    end
end