#!/bin/bash

#simulation_file="resolutionTests/SeedTestStandardDigiNormalLengthSideCuts1mmPlate6cmCo380kBqNoResolutionNoLONU2.root"
simulation_file="sim_regularCrystal_plate6cm30mln.root"
digi_file="separateDigi/LONU/A0177B00978C02265_digi_lonu_sim_regularCrystal_plate6cm_Co390kBq_Interval20.root"
parameters_file="ParametersROOT/par_sim_regularCrystal_plate6cm30mln.root"
numberEvents=30000000

#Function to run simulation
run_simulation() {
    if [ -f "$simulation_file" ]; then
        echo "Warning: The file '$simulation_file' already exists."
        read -p "Do you want to overwrite the file (y/n): " choice
        case "$choice" in
        y|Y )
            echo "Overwriting the file..."
            root -l -q 'simulation.C('$numberEvents',"gadast_test2021.gdml", 0., 180., 0., 360., "'$simulation_file'")'
            ;;
        n|N )
            echo "Operation aborted. The file was not overwritten."
            ;;
        * )
            echo "Invalid input. Operation aborted."
            ;;
        esac
    else
        root -l -q 'simulation.C('$numberEvents',"gadast_test2021.gdml", 0., 180., 0., 360., "'$simulation_file'")'
    fi
}
#Function to run digitization
run_digitization() {
    if [ -f "$digi_file" ]; then
        echo "Warning: The file '$digi_file' already exists."
        read -p "Do you want to overwrite the file (y/n): " choice
        case "$choice" in
        y|Y )
            echo "Overwriting the file..."
            root -l -q 'digitization.C('$numberEvents',"'$simulation_file'", "'$parameters_file'", "'$digi_file'",4)'
            ;;
        n|N )
            echo "Operation aborted. The file was not overwritten."
            ;;
        * )
            echo "Invalid input. Operation aborted."
            ;;
        esac
    else
        root -l -q 'digitization.C('$numberEvents',"'$simulation_file'", "'$parameters_file'", "'$digi_file'",4)'
    fi
}
echo "Choose an option:"
echo "1) Run Simulation only"
echo "2) Run Digitization only"
echo "3) Run Both Simulation and Digitization"
read -p "Enter your choice (1/2/3): " main_choice

case "$main_choice" in
1) 
    echo "Running Simulation only..."
    run_simulation
    ;;
2)
    echo "Running Digitization only..."
    run_digitization
    ;;
3)
    echo "Running Both Simulation and Digitization..."
    run_simulation
    run_digitization
    ;;
*)
    echo "Invalid input. Exiting."
    ;;
esac 
#root -l -q 'sim_digi.C(10000,"gadast_test2021.gdml", 90., 90., 180., 180., "onlyCobalt1stStraight.root")' simulation where sources are oriented through the crystal's axis