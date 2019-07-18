# TASK

# List

defmodule Challenge do
	def main do
		list = [1,2,3,4,5]
		anotherlist = [6,7,8,9,10, 10]
		combinedlist = list ++ anotherlist # concatenating two list
		[head | tail] = combinedlist # head is the first element of the combined list and tail is the rest of the element
		IO.puts 10 in combinedlist # in is used to check whether an element is present in a list or not
		IO.puts 100 in combinedlist

		Enum.each combinedlist, fn value -> IO.puts value * 2 end # iterating over the combined list
		List.delete(combinedlist, 10) # deleting one value from list which is equal to 10
		List.delete_at(combinedlist, 0) # deleting value from list at index 0
		List.insert_at(combinedlist, 0, 1000) # inserting value into list at index 0
		List.first(combinedlist) # first element of the list
		List.last(combinedlist) # last element of the list
	end
end