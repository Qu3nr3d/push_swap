Works with:
* no arguments
./checker
* one number
./checker 3
* two numbers
./checker 4 5
* one argument and Ctr + D
./checker 3
* three arguments and Enter
./checker 4 3 5
* one argument and Enter
./checker 3
* error in args
./checker 4 3 5 5
./checker 4 3 one 5
* with KO
* with OK
* with error in input
./checker 4 3 5
>>pb
>>abrakadabra
* more complicated stream
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)

Gives error for:
* no number
./checker a
* weird stuff between numbers
./checker 12 34 one 3
./checker 12 34 3 one  
./checker one 12 34 3 
* benches
./checker --bench 12 34 3
* duplicates
./checker 45 5 5 6
* weird stdin
abrakadabra
a
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas quis justo a libero pulvinar aliquet. Nam iaculis nisi id tellus sagittis, a accumsan massa scelerisque. Donec finibus malesuada dui ac sodales. Ut efficitur consectetur nulla eu accumsan. Nulla facilisi. Integer neque dolor, mollis ac tempus et, ullamcorper in ipsum.
