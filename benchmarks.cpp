#include "warp.h"

int main(int argc, char* argv[]){

	//using namespace std;

	///////////////////
	// BEGIN PROGRAM //
	///////////////////

	//print banner
	print_banner();

	// names
	unsigned tallycell = 999;
	unsigned N = 0;
	std::string tallyname, filename;
	std::string assemblyname  	= "assembly-lw";
	std::string flibename   	= "flibe";
	std::string fusionname    	= "fusion";
	std::string guidename   	= "guide";
	std::string jezebelname  	= "jezebel";
	std::string pincellname  	= "pincell";
	std::string sodiumpinname  	= "sodiumpin";


	// check
	if(argc<=2){
		printf("MUST ENTER A RUN TYPE : ");
		printf("%s, ",assemblyname.c_str());
		printf("%s, ",flibename.c_str());
		printf("%s, ",fusionname.c_str());
		printf("%s, ",guidename.c_str());
		printf("%s, ",jezebelname.c_str());
		printf("%s, ",pincellname.c_str());
		printf("%s, ",sodiumpinname.c_str());
		printf("and a number of particles to run!\n");
		exit(0);
	}

	// get number of histories to do
	N = atoi(argv[2]);

	// set up geometry
	std::vector<float> mins  (3);
	std::vector<float> maxs  (3);
	std::vector<float> origin(3);
	unsigned type, material, n_topes;
	unsigned prim_id    = 0;
	wgeometry geom;

	// set datapath
	geom.set_datapath("/usr/local/LANL/MCNP6_DATA/xsdir_mcnp6.1");

	if(assemblyname.compare(argv[1])==0){
		//assembly mats
		n_topes    = 4;
		std::vector<std::string> 	topes      (n_topes);
		std::vector<float> 			fracs_fuel (n_topes);
		std::vector<float> 			fracs_water(n_topes);
		topes[0] = "92235.80c";
		topes[1] = "92238.80c";
		topes[2] =  "8016.80c";
		topes[3] =  "1001.80c";
		fracs_fuel[0] = 0.1;  
		fracs_fuel[1] = 0.9;   
		fracs_fuel[2] = 2;   
		fracs_fuel[3] = 0;
		fracs_water[0] = 0;  
		fracs_water[1] = 0;   
		fracs_water[2] = 1;   
		fracs_water[3] = 2;
		float    dens_fuel = 15;
		float 	 dens_water = 3;
		geom.add_material(1,1,n_topes,dens_fuel, topes,fracs_fuel);
		geom.add_material(2,0,n_topes,dens_water,topes,fracs_water);

		// run stuff
		tallycell = 316;   //center pin
		filename = assemblyname;
		tallyname = assemblyname;
		tallyname.append(".tally");
	
		// assembly geom
		type=1;
		material=1;
		mins[0]=-1.0;
		mins[1]=-1.0;
		mins[2]=-20.0;
		maxs[0]= 1.0;
		maxs[1]= 1.0;
		maxs[2]= 20.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.make_hex_array(prim_id,15,0.0,0.0,1.164,1); 

		type=0;
		material=2;
		mins[0]=-48;
		mins[1]=-48;
		mins[2]=-48;
		maxs[0]=48;
		maxs[1]=48;
		maxs[2]=48;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,999,0,0,0,0,0);
		//geom.print_all();
		//geom.update();
		//geom.print_summary();
	}
	else if(flibename.compare(argv[1])==0){
		
	}
	else if(fusionname.compare(argv[1])==0){
		// fusion mats
		n_topes = 18;
		std::vector<std::string> topes  (n_topes);
		std::vector<float>  void_fracs  (n_topes);
		std::vector<float>   sic_fracs  (n_topes);
		std::vector<float>    li_fracs  (n_topes);
		std::vector<float>    ss_fracs  (n_topes);
		topes[0]  =  "6000.80c";
		topes[1]  = "14028.80c";
		topes[2]  = "14029.80c";
		topes[3]  = "14030.80c";
		topes[4]  =  "3006.80c";
		topes[5]  =  "3007.80c";
		topes[6]  = "26054.80c";
		topes[7]  = "26056.80c";
		topes[8]  = "26057.80c";
		topes[9]  = "26058.80c";
		topes[10] = "24050.80c";
		topes[11] = "24052.80c";
		topes[12] = "24053.80c";
		topes[13] = "24054.80c";
		topes[14] = "28058.80c";
		topes[15] = "28060.80c";
		topes[16] = "28062.80c";
		topes[17] = "28064.80c";

		void_fracs[0]  = 0.0;
		void_fracs[1]  = 0.0;
		void_fracs[2]  = 0.0;
		void_fracs[3]  = 0.0;
		void_fracs[4]  = 0.0;
		void_fracs[5]  = 0.0;
		void_fracs[6]  = 0.0;
		void_fracs[7]  = 0.0;
		void_fracs[8]  = 0.0;
		void_fracs[9]  = 0.0;
		void_fracs[10] = 0.0;
		void_fracs[11] = 0.0;
		void_fracs[12] = 0.0;
		void_fracs[13] = 0.0;
		void_fracs[14] = 0.0;
		void_fracs[15] = 0.0;
		void_fracs[16] = 0.0;
		void_fracs[17] = 0.0;

		sic_fracs[0]  = 1.0;
		sic_fracs[1]  = 0.9223;
		sic_fracs[2]  = 0.0467;
		sic_fracs[3]  = 0.0310;
		sic_fracs[4]  = 0.0;
		sic_fracs[5]  = 0.0;
		sic_fracs[6]  = 0.0;
		sic_fracs[7]  = 0.0;
		sic_fracs[8]  = 0.0;
		sic_fracs[9]  = 0.0;
		sic_fracs[10] = 0.0;
		sic_fracs[11] = 0.0;
		sic_fracs[12] = 0.0;
		sic_fracs[13] = 0.0;
		sic_fracs[14] = 0.0;
		sic_fracs[15] = 0.0;
		sic_fracs[16] = 0.0;
		sic_fracs[17] = 0.0;

		li_fracs[0]  = 0.0;
		li_fracs[1]  = 0.0;
		li_fracs[2]  = 0.0;
		li_fracs[3]  = 0.0;
		li_fracs[4]  = 0.075;
		li_fracs[5]  = 0.925;
		li_fracs[6]  = 0.0;
		li_fracs[7]  = 0.0;
		li_fracs[8]  = 0.0;
		li_fracs[9]  = 0.0;
		li_fracs[10] = 0.0;
		li_fracs[11] = 0.0;
		li_fracs[12] = 0.0;
		li_fracs[13] = 0.0;
		li_fracs[14] = 0.0;
		li_fracs[15] = 0.0;
		li_fracs[16] = 0.0;
		li_fracs[17] = 0.0;

		ss_fracs[0]  = 0.0;
		ss_fracs[1]  = 0.0;
		ss_fracs[2]  = 0.0;
		ss_fracs[3]  = 0.0;
		ss_fracs[4]  = 0.0;
		ss_fracs[5]  = 0.0;
		ss_fracs[6]  = 0.0435;
		ss_fracs[7]  = 0.6879;
		ss_fracs[8]  = 0.0165;
		ss_fracs[9]  = 0.0021;
		ss_fracs[10] = 0.0065;
		ss_fracs[11] = 0.1257;
		ss_fracs[12] = 0.0143;
		ss_fracs[13] = 0.0035;
		ss_fracs[14] = 0.0681;
		ss_fracs[15] = 0.0262;
		ss_fracs[16] = 0.0036;
		ss_fracs[17] = 0.0009;

		float   void_dens= 0.000;
		float   sic_dens = 3.210;
		float    li_dens = 0.534;
		float    ss_dens = 7.990;
		geom.add_material(0,0,n_topes,void_dens,topes,void_fracs);
		geom.add_material(1,0,n_topes, sic_dens,topes, sic_fracs);
		geom.add_material(2,0,n_topes,  li_dens,topes,  li_fracs);
		geom.add_material(3,0,n_topes,  ss_dens,topes,  ss_fracs);
		
		// run stuff
		tallycell = 999;
		filename  = fusionname;
		tallyname = fusionname;
		tallyname.append(".tally");
	
		//fusion geom
		type=3;
		material=0;
		mins[0]= -150.0;
		mins[1]= -150.0;
		mins[2]= -150.0;
		maxs[0]=  150.0;
		maxs[1]=  150.0;
		maxs[2]=  150.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,0,0,0,0,0,0);

		type=3;
		material=1;
		mins[0]= -151.0;
		mins[1]= -151.0;
		mins[2]= -151.0;
		maxs[0]=  151.0;
		maxs[1]=  151.0;
		maxs[2]=  151.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,1,0,0,0,0,0);

		type=3;
		material=2;
		mins[0]= -156.0;
		mins[1]= -156.0;
		mins[2]= -156.0;
		maxs[0]=  156.0;
		maxs[1]=  156.0;
		maxs[2]=  156.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,2,0,0,0,0,0);

		type=3;
		material=3;
		mins[0]= -160.0;
		mins[1]= -160.0;
		mins[2]= -160.0;
		maxs[0]=  160.0;
		maxs[1]=  160.0;
		maxs[2]=  160.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,3,0,0,0,0,0);

	}
	else if(guidename.compare(argv[1])==0){
		
	}
	else if(jezebelname.compare(argv[1])==0){
		// jezebel mats
		n_topes = 6;
		std::vector<std::string> topes (n_topes);
		std::vector<float>    fracs (n_topes);
		topes[0] = "94239.80c";
		topes[1] = "94240.80c";
		topes[2] = "94241.80c";
		topes[3] = "94242.80c";
		topes[4] = "31069.80c";
		topes[5] = "31071.80c";
		fracs[0] = 0.029934;
		fracs[1] = 0.0078754;
		fracs[2] = 0.0012146;
		fracs[3] = 0.00015672;
		fracs[4] = 0.00082482942;
		fracs[5] = 0.00054737058;
		float    dens = 15.730;
		geom.add_material(1,1,n_topes,dens,topes,fracs);
		
		// run stuff
		tallycell = 999;
		filename = jezebelname;
		tallyname = jezebelname;
		tallyname.append(".tally");
	
		//jezebel geom
		type=3;
		material=1;
		mins[0]= -6.6595;
		mins[1]= -6.6595;
		mins[2]= -6.6595;
		maxs[0]=  6.6595;
		maxs[1]=  6.6595;
		maxs[2]=  6.6595;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,999,0,0,0,0,0);
		
	}
	else if(pincellname.compare(argv[1])==0){
		// pincell mats
		n_topes = 9;
		std::vector<std::string> topes (n_topes);
		std::vector<float>    fracs_fuel  (n_topes);
		std::vector<float>    fracs_water (n_topes);
		std::vector<float>    fracs_clad  (n_topes);
		topes[0]="92235.03c";
		topes[1]="92238.03c";
		topes[2]="8016.03c" ;
		topes[3]="1002.03c" ;
		topes[4]="40090.80c";
 		topes[5]="40091.80c";
 		topes[6]="40092.80c";
 		topes[7]="40094.80c";
 		topes[8]="40096.80c";
		fracs_fuel[0] = 0.1;  
		fracs_fuel[1] = 0.9;   
		fracs_fuel[2] = 2;   
		fracs_fuel[3] = 0;
		fracs_fuel[4] = 0;
		fracs_fuel[5] = 0;
		fracs_fuel[6] = 0;  
		fracs_fuel[7] = 0;
		fracs_fuel[8] = 0;
	  	fracs_water[0] = 0; 
		fracs_water[1] = 0; 
		fracs_water[2] = 1;   
		fracs_water[3] = 2;
		fracs_water[4] = 0;
		fracs_water[5] = 0;
		fracs_water[6] = 0;  
		fracs_water[7] = 0;
		fracs_water[8] = 0;
	    fracs_clad[0] = 0; 
		fracs_clad[1] = 0; 
		fracs_clad[2] = 0;   
		fracs_clad[3] = 0;
		fracs_clad[4] = 0.5145;
		fracs_clad[5] = 0.1122;
		fracs_clad[6] = 0.1715;  
		fracs_clad[7] = 0.1738;
		fracs_clad[8] = 0.0280;
	   
	
		float    dens_fuel = 10.97;
		float 	 dens_water = 1.11;
		float 	 dens_clad = 6.52;
		geom.add_material(1,1,n_topes,dens_fuel, topes,fracs_fuel);
		geom.add_material(2,0,n_topes,dens_water,topes,fracs_water);
		geom.add_material(3,0,n_topes,dens_clad,topes,fracs_clad);
		
		// run stuff
		tallycell = 1;
		filename = pincellname;
		tallyname = pincellname;
		tallyname.append(".tally");
	
		//pin cell
		type=1;
		material=1;
		mins[0]=-2;
		mins[1]=-2;
		mins[2]=-20;
		maxs[0]= 2; 
		maxs[1]= 2; 
		maxs[2]= 20;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,1,0,0,0,0,0);

		//clad
		type=1;
		material=3;
		mins[0]=-2.2;
		mins[1]=-2.2;
		mins[2]=-20;
		maxs[0]= 2.2; 
		maxs[1]= 2.2; 
		maxs[2]= 20;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,2,0,0,0,0,0);

		//water 
		type=0;
		material=2;
		mins[0]=-5.0;
		mins[1]=-5.0;
		mins[2]=-25.0;
		maxs[0]= 5.0;
		maxs[1]= 5.0;
		maxs[2]= 25.0;
		origin[0]=0.0;
		origin[1]=0.0;
		origin[2]=0.0;
		prim_id=geom.add_primitive(type,material,mins,maxs,origin);
		geom.add_transform(prim_id,999,0,0,0,0,0);
	}
	else if(sodiumpinname.compare(argv[1])==0){
		
	}
	else{
		printf("MUST ENTER A *VALID* RUN TYPE : ");
		printf("%s, ",assemblyname.c_str());
		printf("%s, ",flibename.c_str());
		printf("%s, ",fusionname.c_str());
		printf("%s, ",guidename.c_str());
		printf("%s, ",jezebelname.c_str());
		printf("%s, ",pincellname.c_str());
		printf("%s, ",sodiumpinname.c_str());
		printf("and a number of particles to run!\n");
		exit(0);
	}

	// finalize geom
	geom.set_outer_cell(999,1);  // cell, BC  1=black, 2=specular
	geom.update();
	if(geom.check()){std::cout << "geometry failed check!\n"; return 1;}
	//geom.print_all();
	geom.print_summary();

	///////////////////////////////////
	// INIT OptiX STUFF for plotting //
	///////////////////////////////////

	// trace geom if requested
	// make new context that fits the reqested image size, trace, then destroy to free resources
	//unsigned geom_width  = 1024; 
	//unsigned geom_height = 1024;
	//unsigned N_geom = geom_width*geom_height;
	//optix_stuff geom_optix ( N_geom , 4 );
	//geom_optix.init(geom,0,"Sbvh");
	//geom_optix.trace_geometry(geom_width,geom_height,"geom.png");
	//geom_optix.~optix_stuff();


	/////////////////////////////////////////////////////////////////
	// INIT CUDA and HISTORY STUFF and LOAD/UNIONIZE CROS SECTIONS //
	/////////////////////////////////////////////////////////////////

	whistory hist ( N , geom );
	hist.set_print_level(2);
	hist.set_device(0);
	hist.init();
	hist.print_xs_data();
	hist.print_materials_table();

	/////////////////////////////////////
	// converge fission source and run //
	/////////////////////////////////////

	hist.set_run_type("criticality");
	hist.set_tally_cell(tallycell);
	hist.set_run_param(40,20);  //run, skip
	hist.set_filename(filename);
	hist.run();
	hist.write_tally(0);
	//hist.write_xs_data("xsdata");

	return 0;

}

