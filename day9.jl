#extrapolate first star
function extrap(line)
        inp = [split(line, ' ') .|> x->parse(Int64,x)]
        while !iszero(last(inp))
                push!(inp, [last(inp)[i]-last(inp)[i-1] for i in 2:length(last(inp))])
        end
        for i in 1:(length(inp)-1)
                push!(inp[length(inp)-i], last(inp[length(inp)-i])+last(inp[length(inp)-i+1]))
        end
        last(first(inp))
end

#estrapolate second star
function extrapback(line)
               inp = [split(line, ' ') .|> x->parse(Int64,x)]
               while !iszero(last(inp))
                       push!(inp, [last(inp)[i]-last(inp)[i-1] for i in 2:length(last(inp))])
               end
               for i in 1:(length(inp)-1)
                       pushfirst!(inp[length(inp)-i], first(inp[length(inp)-i])-first(inp[length(inp)-i+1]))
               end
               first(first(inp))
       end

open("input9") do f
        fstar = Int128(0)
        sstar = Int128(0)
        while ! eof(f)
                s = readline(f)
                if length(s) > 1
                        fstar += s |> extrap
                        sstar += s |> extrapback
                end
        end
        println("first star: ", fstar)
        println("second star: ", sstar)
end
