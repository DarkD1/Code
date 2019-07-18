defmodule M do
  def main do
    do_something() # function to do_something :p
  end
  def do_something do
    firstname = "Sazzad"
    lastname = "Shopno"
    fullname = firstname <> " " <> lastname # appending two strings 

    IO.puts(fullname) # printing the appended string
    IO.inspect(String.split(fullname, " ")) # Divides a string into parts based on a pattern

    IO.puts("Name Length: #{String.length(fullname)}") # string length
    IO.puts("Firstname Length: #{String.length(firstname)}")

    IO.puts("First index: #{String.at(fullname, 0)}") # getting the value of a particular index of a string, it is zero based
    IO.puts("Last index: #{String.at(fullname, -1)}")
    IO.puts("100 index: #{String.at(fullname, 100)}") # returns Nil

    IO.puts("Bag Distance: #{String.bag_distance(fullname, firstname)}") # Returns a float value between 0 and 1 representing the bag distance between string1 and string2.
    #The bag distance is meant to be an efficient approximation of the distance between two strings to quickly rule out strings that are largely different.
    
    IO.inspect(String.codepoints(fullname)) # Returns all codepoints in the string

    IO.puts("Contains zz: #{String.contains?(fullname, "zz")}") # Checks if string contains any of the given contents
    IO.puts("#{String.contains?(fullname, ["Sazzad", "Hossain"])}") # returns true becuase one of the element exists in string
    IO.puts("#{String.contains?(fullname, "")}") # an empty string always match

    IO.puts("#{String.duplicate(firstname, 5)}") # Returns a string duplicated n times.

    IO.puts(String.ends_with(firstname, "Shopno")) # Returns true if string ends with any of the suffixes given.
    IO.puts({String.ends_with(firstname, ["Shopno", "Sazzad"]))
    IO.puts(String.ends_with(firstname, "")) # an empty string always match

    IO.puts(String.equivalent?("sazzad", "SAZZAD")) # Returns true if string1 is canonically equivalent to 'string2'.
    IO.puts(String.equivalent?(firstname, lastname))

    IO.puts("#{String.reverse(fullname)}") # reverses a string

    IO.puts("#{String.upcase(fullname)}") # Converts all characters in the given string to uppercase according to mode

    IO.puts("#{String.downcase(fullname)}") # Converts all characters in the given string to lowercase according to mode

    IO.puts("#{String.capitalize(fullname)}") # Converts the first character in the given string to uppercase and the remainder to lowercase according to mode
    
    IO.puts("Substring from 0 to 6: #{String.slice(fullname, 0, 6)}") # Returns a substring starting at the offset start, and of length len
  end
end