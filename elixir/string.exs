defmodule M do
  def main do
    do_something() # function to do_something :p
  end
  def do_something do
    firstname = "Sazzad"
    lastname = "Shopno"
    fullname = firstname <> " " <> lastname # appending two strings 
    IO.puts(fullname) # printing the appended string
    IO.inspect(String.split(fullname, " ")) # splitting a string
    IO.puts("Name Length: #{String.length(fullname)}") # string length
    IO.puts("Index 2: #{String.at(fullname, 2)}") # getting the value of a particular index of a string, it is zero based
    IO.puts("Contains zz: #{String.contains?(fullname, "zz")}") # checking if a substring exists in a string or not
    IO.puts("#{String.reverse(fullname)}") # reversing a string
    IO.puts("#{String.upcase(fullname)}") # uppercased a string
    IO.puts("#{String.downcase(fullname)}") # lowercased a string
    IO.puts("#{String.capitalize(fullname)}") # capitalizing first character of a string
  end
end