#!/bin/bash
file_postfix="test.root"
simulation_file="sim_${file_postfix}"
digi_file="digi_${file_postfix}"
numberEvents=30000
geometry_file="gadast_test2021.gdml"
gammas_multiplicity=4

#Function to run a simulation
run_simulation() {
    if [ -f "$simulation_file" ]; then
        echo "Warning: The file '$simulation_file' already exists."
        read -p "Do you want to overwrite the file (y/n): " choice
        case "$choice" in
        y|Y )
            echo "Overwriting the file..."
            root -l -q 'simulation.C('$numberEvents',"'$geometry_file'",'$gammas_multiplicity', 0., 180., 0., 360., "'$file_postfix'")'
            ;;
        n|N )
            echo "Operation aborted. The file was not overwritten."
            ;;
        * )
            echo "Invalid input. Operation aborted."
            ;;
        esac
    else
        root -l -q 'simulation.C('$numberEvents',"'$geometry_file'",'$gammas_multiplicity', 0., 180., 0., 360., "'$file_postfix'")'
    fi
}
#Function to run the digitization
run_digitization() {
    if [ -f "$digi_file" ]; then
        echo "Warning: The file '$digi_file' already exists."
        read -p "Do you want to overwrite the file (y/n): " choice
        case "$choice" in
        y|Y )
            echo "Overwriting the file..."
            root -l -q 'digitization.C('$numberEvents','$gammas_multiplicity',"'$file_postfix'")'
            ;;
        n|N )
            echo "Operation aborted. The file was not overwritten."
            ;;
        * )
            echo "Invalid input. Operation aborted."
            ;;
        esac
    else
        root -l -q 'digitization.C('$numberEvents','$gammas_multiplicity',"'$file_postfix'")'
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