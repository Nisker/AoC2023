println("day1 silver")
open("input") do f
	out = Int128(0)
	while ! eof(f)
		s = readline(f)
		if length(s) > 1
			out += s |>  filter(isdigit).|> [first,last] |> String|> x->parse(Int64,x)
		end
	end
	println("answer: ",out)
end

println("day1 gold")
open("input") do f
	out = Int128(0)
	while ! eof(f)
		ss = readline(f)
		s1 = replace(ss, Dict(["one"=>"1", "two"=>"2", "three"=>"3", "four"=>"4", "five"=>"5", "six"=>"6", "seven"=>"7","eight"=>"8", "nine"=>"9"])...)
		s =  replace(s1, Dict(["1ight"=>"18", "2ne"=>"21", "3ight"=>"38", "7ine"=>"79", "5ight"=>"58", "8ree"=>"83", "8wo"=>"82", "9ight"=>"98"])...)
		if length(s) > 1
			par = s |>  filter(isdigit).|> [first,last] |> String|> x->parse(Int64,x)
			out += par

			# println("$ss $s1 $s $par $out")
		end
	end
	println("answer: ",out)
end
