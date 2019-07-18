# TASK

# Conditional Statements

defmodule Challenge do
  def main do
  	age = 10
  	
  	# If statement
  	if age == 10 do
  		IO.puts "You are young!!"
  	end
  	
  	# Oneline if statement
  	if age == 10, do: IO.puts "You are young again!!"

  	# If..else statement
  	if age == 18 do
  	 	IO.puts "You are adult"
  	 else
  	 	IO.puts "You are not adult"
  	 end 

  	 # Oneline if..else statement
  	 IO.puts "Hello : #{if age == 18, do: "You are adult" , else: "Your age is not good enough"}"

  	 # Unless statement
  	 unless age == 18 do
  	  	IO.puts "You are not eighteen! ;)"
  	  end

      # Unless..else statement
      unless age == 18 do
        IO.puts "What are you doing here??"
      else
        IO.puts "This place is perfect for you ;)"
      end

      # Else..if ladder 
      cond do
        age == 10 -> IO.puts "You are 10"
        age == 18 -> IO.puts "You are 18"
        age == 5 -> IO.puts "You are 5"
        true -> IO.puts "We dont know you" # else
      end

      # Switch case
      case age do
        10 -> IO.puts "10"
        28 -> IO.puts "28"
        _ -> IO.puts "Neither 10 nor 28" # default
      end
  end
end