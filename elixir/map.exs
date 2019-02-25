# TASK

# Map implementation

defmodule Challenge do
  def main do
    mp = %{1 => "One", 2 => "Two", atom: 81} # %{} syntax of map
    m = Map.fetch(mp, 1) # one way to fetch value using key
    n = Map.fetch(mp, 3) # if there is no data exist then it returns nil / error
    IO.inspect m
    IO.inspect n
    IO.inspect mp.atom # can be used to access a value which key is an atom but if the key is not atom then it will cause an error
  	mp2 = Dict.put_new(mp, "Sazzad", "Shopno") # inseting new key and value in map
  end
end