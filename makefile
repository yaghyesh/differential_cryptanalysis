abcd:
	g++ random_bits.cpp &&./a.out
	g++ random_input.cpp &&./a.out 
	./script.sh
	sed 's/ /\n/g' output.txt > output_clean.txt
	g++ permute.cpp &&./a.out
	g++ expand.cpp &&./a.out 
	g++ xor_sif_dash.cpp &&./a.out 
	g++ xor_F.cpp &&./a.out 
	g++ count_keys.cpp &&./a.out 