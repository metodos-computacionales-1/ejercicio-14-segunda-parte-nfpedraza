graph.png : exe_14.dat exe_rk14.dat grafica.py
	python grafica.py

exe_14.dat exe_rk14.dat : exe_14.x exe_rk.x
	./exe_14.x exe_rk.x

exe_14.x exe_rk.x : ejercicio_1_14.cpp ejercicio_rk_14.cpp
	c++ Clase_29.cpp -o Clase_29.x
	
clean : 
	rm exe_14.x exe_rk.x exe_14.dat exe_rk14.dat grafica.png
