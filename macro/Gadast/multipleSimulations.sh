#!/bin/bash
#root -l -q 'sim_digi.C(10000,"gadast_test2021.gdml", 90., 90., 180., 180., "onlyCobalt1stStraight.root")' simulation where sources are oriented through the crystal's axis
root -l -q 'sim_digi.C(20000000,"gadast_test2021_reduced_crystal.gdml", 0., 180., 0., 360., "renewedGeometryBothSmallerCrystal2.root")'
#root -l -q 'sim_digi.C(3000000,"gadast_test2021_reduced_crystal.gdml", 0., 180., 0., 360., "defPoisSh4int0to4opposingSidePosMult4smallerCrystalsmallerThickness.root")'