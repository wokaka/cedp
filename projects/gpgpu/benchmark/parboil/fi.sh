rm -f result-0.txt
echo "fi 0 0 0 0 0x80000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-0.txt 
rm -f result-1.txt
echo "fi 0 0 0 0 0x40000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1.txt 
rm -f result-2.txt
echo "fi 0 0 0 0 0x08000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-2.txt 
rm -f result-3.txt
echo "fi 0 0 0 0 0x00800000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-3.txt 
rm -f result-4.txt
echo "fi 0 0 0 0 0x00400000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-4.txt 
rm -f result-5.txt
echo "fi 0 0 0 0 0x00001000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-5.txt 
rm -f result-6.txt
echo "fi 0 0 0 0 0x00000001 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-6.txt 
rm -f result-7.txt
echo "fi 0 0 1 0 0x80000000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-7.txt 
rm -f result-8.txt
echo "fi 0 0 1 0 0x40000000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-8.txt 
rm -f result-9.txt
echo "fi 0 0 1 0 0x08000000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-9.txt 
rm -f result-10.txt
echo "fi 0 0 1 0 0x00800000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-10.txt 
rm -f result-11.txt
echo "fi 0 0 1 0 0x00400000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-11.txt 
rm -f result-12.txt
echo "fi 0 0 1 0 0x00001000 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-12.txt 
rm -f result-13.txt
echo "fi 0 0 1 0 0x00000001 fp_pt phiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-13.txt 
rm -f result-14.txt
echo "fi 0 0 2 0 0x80000000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-14.txt 
rm -f result-15.txt
echo "fi 0 0 2 0 0x40000000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-15.txt 
rm -f result-16.txt
echo "fi 0 0 2 0 0x08000000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-16.txt 
rm -f result-17.txt
echo "fi 0 0 2 0 0x00800000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-17.txt 
rm -f result-18.txt
echo "fi 0 0 2 0 0x00400000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-18.txt 
rm -f result-19.txt
echo "fi 0 0 2 0 0x00001000 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-19.txt 
rm -f result-20.txt
echo "fi 0 0 2 0 0x00000001 fp_pt phiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-20.txt 
rm -f result-21.txt
echo "fi 0 0 3 0 0x80000000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-21.txt 
rm -f result-22.txt
echo "fi 0 0 3 0 0x40000000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-22.txt 
rm -f result-23.txt
echo "fi 0 0 3 0 0x08000000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-23.txt 
rm -f result-24.txt
echo "fi 0 0 3 0 0x00800000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-24.txt 
rm -f result-25.txt
echo "fi 0 0 3 0 0x00400000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-25.txt 
rm -f result-26.txt
echo "fi 0 0 3 0 0x00001000 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-26.txt 
rm -f result-27.txt
echo "fi 0 0 3 0 0x00000001 fp_pt dR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-27.txt 
rm -f result-28.txt
echo "fi 0 0 4 0 0x80000000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-28.txt 
rm -f result-29.txt
echo "fi 0 0 4 0 0x40000000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-29.txt 
rm -f result-30.txt
echo "fi 0 0 4 0 0x08000000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-30.txt 
rm -f result-31.txt
echo "fi 0 0 4 0 0x00800000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-31.txt 
rm -f result-32.txt
echo "fi 0 0 4 0 0x00400000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-32.txt 
rm -f result-33.txt
echo "fi 0 0 4 0 0x00001000 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-33.txt 
rm -f result-34.txt
echo "fi 0 0 4 0 0x00000001 fp_pt dI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-34.txt 
rm -f result-35.txt
echo "fi 0 0 5 0 0x80000000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-35.txt 
rm -f result-36.txt
echo "fi 0 0 5 0 0x40000000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-36.txt 
rm -f result-37.txt
echo "fi 0 0 5 0 0x08000000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-37.txt 
rm -f result-38.txt
echo "fi 0 0 5 0 0x00800000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-38.txt 
rm -f result-39.txt
echo "fi 0 0 5 0 0x00400000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-39.txt 
rm -f result-40.txt
echo "fi 0 0 5 0 0x00001000 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-40.txt 
rm -f result-41.txt
echo "fi 0 0 5 0 0x00000001 fp_pt realRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-41.txt 
rm -f result-42.txt
echo "fi 0 0 6 0 0x80000000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-42.txt 
rm -f result-43.txt
echo "fi 0 0 6 0 0x40000000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-43.txt 
rm -f result-44.txt
echo "fi 0 0 6 0 0x08000000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-44.txt 
rm -f result-45.txt
echo "fi 0 0 6 0 0x00800000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-45.txt 
rm -f result-46.txt
echo "fi 0 0 6 0 0x00400000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-46.txt 
rm -f result-47.txt
echo "fi 0 0 6 0 0x00001000 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-47.txt 
rm -f result-48.txt
echo "fi 0 0 6 0 0x00000001 fp_pt imagRhoPhi" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-48.txt 
rm -f result-49.txt
echo "fi 0 0 14 0 0x80000000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-49.txt 
rm -f result-50.txt
echo "fi 0 0 14 0 0x40000000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-50.txt 
rm -f result-51.txt
echo "fi 0 0 14 0 0x08000000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-51.txt 
rm -f result-52.txt
echo "fi 0 0 14 0 0x00800000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-52.txt 
rm -f result-53.txt
echo "fi 0 0 14 0 0x00400000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-53.txt 
rm -f result-54.txt
echo "fi 0 0 14 0 0x00001000 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-54.txt 
rm -f result-55.txt
echo "fi 0 0 14 0 0x00000001 int indexK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-55.txt 
rm -f result-56.txt
echo "fi 0 0 15 0 0x80000000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-56.txt 
rm -f result-57.txt
echo "fi 0 0 15 0 0x40000000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-57.txt 
rm -f result-58.txt
echo "fi 0 0 15 0 0x08000000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-58.txt 
rm -f result-59.txt
echo "fi 0 0 15 0 0x00800000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-59.txt 
rm -f result-60.txt
echo "fi 0 0 15 0 0x00400000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-60.txt 
rm -f result-61.txt
echo "fi 0 0 15 0 0x00001000 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-61.txt 
rm -f result-62.txt
echo "fi 0 0 15 0 0x00000001 fp rPhiR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-62.txt 
rm -f result-63.txt
echo "fi 0 0 16 0 0x80000000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-63.txt 
rm -f result-64.txt
echo "fi 0 0 16 0 0x40000000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-64.txt 
rm -f result-65.txt
echo "fi 0 0 16 0 0x08000000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-65.txt 
rm -f result-66.txt
echo "fi 0 0 16 0 0x00800000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-66.txt 
rm -f result-67.txt
echo "fi 0 0 16 0 0x00400000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-67.txt 
rm -f result-68.txt
echo "fi 0 0 16 0 0x00001000 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-68.txt 
rm -f result-69.txt
echo "fi 0 0 16 0 0x00000001 fp rPhiI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-69.txt 
rm -f result-70.txt
echo "fi 0 0 17 0 0x80000000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-70.txt 
rm -f result-71.txt
echo "fi 0 0 17 0 0x40000000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-71.txt 
rm -f result-72.txt
echo "fi 0 0 17 0 0x08000000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-72.txt 
rm -f result-73.txt
echo "fi 0 0 17 0 0x00800000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-73.txt 
rm -f result-74.txt
echo "fi 0 0 17 0 0x00400000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-74.txt 
rm -f result-75.txt
echo "fi 0 0 17 0 0x00001000 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-75.txt 
rm -f result-76.txt
echo "fi 0 0 17 0 0x00000001 fp rDR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-76.txt 
rm -f result-77.txt
echo "fi 0 0 18 0 0x80000000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-77.txt 
rm -f result-78.txt
echo "fi 0 0 18 0 0x40000000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-78.txt 
rm -f result-79.txt
echo "fi 0 0 18 0 0x08000000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-79.txt 
rm -f result-80.txt
echo "fi 0 0 18 0 0x00800000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-80.txt 
rm -f result-81.txt
echo "fi 0 0 18 0 0x00400000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-81.txt 
rm -f result-82.txt
echo "fi 0 0 18 0 0x00001000 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-82.txt 
rm -f result-83.txt
echo "fi 0 0 18 0 0x00000001 fp rDI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-83.txt 
rm -f result-84.txt
echo "fi 0 0 19 0 0x80000000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-84.txt 
rm -f result-85.txt
echo "fi 0 0 19 0 0x40000000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-85.txt 
rm -f result-86.txt
echo "fi 0 0 19 0 0x08000000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-86.txt 
rm -f result-87.txt
echo "fi 0 0 19 0 0x00800000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-87.txt 
rm -f result-88.txt
echo "fi 0 0 19 0 0x00400000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-88.txt 
rm -f result-89.txt
echo "fi 0 0 19 0 0x00001000 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-89.txt 
rm -f result-90.txt
echo "fi 0 0 19 0 0x00000001 fp realRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-90.txt 
rm -f result-91.txt
echo "fi 0 0 20 0 0x80000000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-91.txt 
rm -f result-92.txt
echo "fi 0 0 20 0 0x40000000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-92.txt 
rm -f result-93.txt
echo "fi 0 0 20 0 0x08000000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-93.txt 
rm -f result-94.txt
echo "fi 0 0 20 0 0x00800000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-94.txt 
rm -f result-95.txt
echo "fi 0 0 20 0 0x00400000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-95.txt 
rm -f result-96.txt
echo "fi 0 0 20 0 0x00001000 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-96.txt 
rm -f result-97.txt
echo "fi 0 0 20 0 0x00000001 fp imagRhoPhi[indexK]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-97.txt 
rm -f result-98.txt
echo "fi 1 0 7 0 0x80000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-98.txt 
rm -f result-99.txt
echo "fi 1 0 7 0 0x40000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-99.txt 
rm -f result-100.txt
echo "fi 1 0 7 0 0x08000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-100.txt 
rm -f result-101.txt
echo "fi 1 0 7 0 0x00800000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-101.txt 
rm -f result-102.txt
echo "fi 1 0 7 0 0x00400000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-102.txt 
rm -f result-103.txt
echo "fi 1 0 7 0 0x00001000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-103.txt 
rm -f result-104.txt
echo "fi 1 0 7 0 0x00000001 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-104.txt 
rm -f result-105.txt
echo "fi 1 0 8 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-105.txt 
rm -f result-106.txt
echo "fi 1 0 8 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-106.txt 
rm -f result-107.txt
echo "fi 1 0 8 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-107.txt 
rm -f result-108.txt
echo "fi 1 0 8 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-108.txt 
rm -f result-109.txt
echo "fi 1 0 8 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-109.txt 
rm -f result-110.txt
echo "fi 1 0 8 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-110.txt 
rm -f result-111.txt
echo "fi 1 0 8 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-111.txt 
rm -f result-112.txt
echo "fi 1 0 9 0 0x80000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-112.txt 
rm -f result-113.txt
echo "fi 1 0 9 0 0x40000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-113.txt 
rm -f result-114.txt
echo "fi 1 0 9 0 0x08000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-114.txt 
rm -f result-115.txt
echo "fi 1 0 9 0 0x00800000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-115.txt 
rm -f result-116.txt
echo "fi 1 0 9 0 0x00400000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-116.txt 
rm -f result-117.txt
echo "fi 1 0 9 0 0x00001000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-117.txt 
rm -f result-118.txt
echo "fi 1 0 9 0 0x00000001 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-118.txt 
rm -f result-119.txt
echo "fi 1 0 10 0 0x80000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-119.txt 
rm -f result-120.txt
echo "fi 1 0 10 0 0x40000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-120.txt 
rm -f result-121.txt
echo "fi 1 0 10 0 0x08000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-121.txt 
rm -f result-122.txt
echo "fi 1 0 10 0 0x00800000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-122.txt 
rm -f result-123.txt
echo "fi 1 0 10 0 0x00400000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-123.txt 
rm -f result-124.txt
echo "fi 1 0 10 0 0x00001000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-124.txt 
rm -f result-125.txt
echo "fi 1 0 10 0 0x00000001 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-125.txt 
rm -f result-126.txt
echo "fi 1 0 11 0 0x80000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-126.txt 
rm -f result-127.txt
echo "fi 1 0 11 0 0x40000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-127.txt 
rm -f result-128.txt
echo "fi 1 0 11 0 0x08000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-128.txt 
rm -f result-129.txt
echo "fi 1 0 11 0 0x00800000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-129.txt 
rm -f result-130.txt
echo "fi 1 0 11 0 0x00400000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-130.txt 
rm -f result-131.txt
echo "fi 1 0 11 0 0x00001000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-131.txt 
rm -f result-132.txt
echo "fi 1 0 11 0 0x00000001 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-132.txt 
rm -f result-133.txt
echo "fi 1 0 12 0 0x80000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-133.txt 
rm -f result-134.txt
echo "fi 1 0 12 0 0x40000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-134.txt 
rm -f result-135.txt
echo "fi 1 0 12 0 0x08000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-135.txt 
rm -f result-136.txt
echo "fi 1 0 12 0 0x00800000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-136.txt 
rm -f result-137.txt
echo "fi 1 0 12 0 0x00400000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-137.txt 
rm -f result-138.txt
echo "fi 1 0 12 0 0x00001000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-138.txt 
rm -f result-139.txt
echo "fi 1 0 12 0 0x00000001 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-139.txt 
rm -f result-140.txt
echo "fi 1 0 13 0 0x80000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-140.txt 
rm -f result-141.txt
echo "fi 1 0 13 0 0x40000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-141.txt 
rm -f result-142.txt
echo "fi 1 0 13 0 0x08000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-142.txt 
rm -f result-143.txt
echo "fi 1 0 13 0 0x00800000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-143.txt 
rm -f result-144.txt
echo "fi 1 0 13 0 0x00400000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-144.txt 
rm -f result-145.txt
echo "fi 1 0 13 0 0x00001000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-145.txt 
rm -f result-146.txt
echo "fi 1 0 13 0 0x00000001 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-146.txt 
rm -f result-147.txt
echo "fi 1 0 21 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-147.txt 
rm -f result-148.txt
echo "fi 1 0 21 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-148.txt 
rm -f result-149.txt
echo "fi 1 0 21 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-149.txt 
rm -f result-150.txt
echo "fi 1 0 21 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-150.txt 
rm -f result-151.txt
echo "fi 1 0 21 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-151.txt 
rm -f result-152.txt
echo "fi 1 0 21 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-152.txt 
rm -f result-153.txt
echo "fi 1 0 21 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-153.txt 
rm -f result-154.txt
echo "fi 1 0 22 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-154.txt 
rm -f result-155.txt
echo "fi 1 0 22 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-155.txt 
rm -f result-156.txt
echo "fi 1 0 22 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-156.txt 
rm -f result-157.txt
echo "fi 1 0 22 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-157.txt 
rm -f result-158.txt
echo "fi 1 0 22 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-158.txt 
rm -f result-159.txt
echo "fi 1 0 22 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-159.txt 
rm -f result-160.txt
echo "fi 1 0 22 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-160.txt 
rm -f result-161.txt
echo "fi 1 0 23 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-161.txt 
rm -f result-162.txt
echo "fi 1 0 23 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-162.txt 
rm -f result-163.txt
echo "fi 1 0 23 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-163.txt 
rm -f result-164.txt
echo "fi 1 0 23 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-164.txt 
rm -f result-165.txt
echo "fi 1 0 23 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-165.txt 
rm -f result-166.txt
echo "fi 1 0 23 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-166.txt 
rm -f result-167.txt
echo "fi 1 0 23 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-167.txt 
rm -f result-168.txt
echo "fi 1 0 24 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-168.txt 
rm -f result-169.txt
echo "fi 1 0 24 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-169.txt 
rm -f result-170.txt
echo "fi 1 0 24 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-170.txt 
rm -f result-171.txt
echo "fi 1 0 24 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-171.txt 
rm -f result-172.txt
echo "fi 1 0 24 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-172.txt 
rm -f result-173.txt
echo "fi 1 0 24 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-173.txt 
rm -f result-174.txt
echo "fi 1 0 24 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-174.txt 
rm -f result-175.txt
echo "fi 1 0 25 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-175.txt 
rm -f result-176.txt
echo "fi 1 0 25 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-176.txt 
rm -f result-177.txt
echo "fi 1 0 25 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-177.txt 
rm -f result-178.txt
echo "fi 1 0 25 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-178.txt 
rm -f result-179.txt
echo "fi 1 0 25 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-179.txt 
rm -f result-180.txt
echo "fi 1 0 25 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-180.txt 
rm -f result-181.txt
echo "fi 1 0 25 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-181.txt 
rm -f result-182.txt
echo "fi 1 0 26 0 0x80000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-182.txt 
rm -f result-183.txt
echo "fi 1 0 26 0 0x40000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-183.txt 
rm -f result-184.txt
echo "fi 1 0 26 0 0x08000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-184.txt 
rm -f result-185.txt
echo "fi 1 0 26 0 0x00800000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-185.txt 
rm -f result-186.txt
echo "fi 1 0 26 0 0x00400000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-186.txt 
rm -f result-187.txt
echo "fi 1 0 26 0 0x00001000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-187.txt 
rm -f result-188.txt
echo "fi 1 0 26 0 0x00000001 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-188.txt 
rm -f result-189.txt
echo "fi 1 0 27 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-189.txt 
rm -f result-190.txt
echo "fi 1 0 27 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-190.txt 
rm -f result-191.txt
echo "fi 1 0 27 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-191.txt 
rm -f result-192.txt
echo "fi 1 0 27 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-192.txt 
rm -f result-193.txt
echo "fi 1 0 27 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-193.txt 
rm -f result-194.txt
echo "fi 1 0 27 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-194.txt 
rm -f result-195.txt
echo "fi 1 0 27 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-195.txt 
rm -f result-196.txt
echo "fi 1 0 28 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-196.txt 
rm -f result-197.txt
echo "fi 1 0 28 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-197.txt 
rm -f result-198.txt
echo "fi 1 0 28 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-198.txt 
rm -f result-199.txt
echo "fi 1 0 28 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-199.txt 
rm -f result-200.txt
echo "fi 1 0 28 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-200.txt 
rm -f result-201.txt
echo "fi 1 0 28 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-201.txt 
rm -f result-202.txt
echo "fi 1 0 28 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-202.txt 
rm -f result-203.txt
echo "fi 1 0 29 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-203.txt 
rm -f result-204.txt
echo "fi 1 0 29 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-204.txt 
rm -f result-205.txt
echo "fi 1 0 29 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-205.txt 
rm -f result-206.txt
echo "fi 1 0 29 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-206.txt 
rm -f result-207.txt
echo "fi 1 0 29 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-207.txt 
rm -f result-208.txt
echo "fi 1 0 29 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-208.txt 
rm -f result-209.txt
echo "fi 1 0 29 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-209.txt 
rm -f result-210.txt
echo "fi 1 0 30 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-210.txt 
rm -f result-211.txt
echo "fi 1 0 30 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-211.txt 
rm -f result-212.txt
echo "fi 1 0 30 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-212.txt 
rm -f result-213.txt
echo "fi 1 0 30 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-213.txt 
rm -f result-214.txt
echo "fi 1 0 30 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-214.txt 
rm -f result-215.txt
echo "fi 1 0 30 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-215.txt 
rm -f result-216.txt
echo "fi 1 0 30 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-216.txt 
rm -f result-217.txt
echo "fi 1 0 31 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-217.txt 
rm -f result-218.txt
echo "fi 1 0 31 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-218.txt 
rm -f result-219.txt
echo "fi 1 0 31 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-219.txt 
rm -f result-220.txt
echo "fi 1 0 31 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-220.txt 
rm -f result-221.txt
echo "fi 1 0 31 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-221.txt 
rm -f result-222.txt
echo "fi 1 0 31 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-222.txt 
rm -f result-223.txt
echo "fi 1 0 31 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-223.txt 
rm -f result-224.txt
echo "fi 1 0 32 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-224.txt 
rm -f result-225.txt
echo "fi 1 0 32 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-225.txt 
rm -f result-226.txt
echo "fi 1 0 32 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-226.txt 
rm -f result-227.txt
echo "fi 1 0 32 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-227.txt 
rm -f result-228.txt
echo "fi 1 0 32 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-228.txt 
rm -f result-229.txt
echo "fi 1 0 32 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-229.txt 
rm -f result-230.txt
echo "fi 1 0 32 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-230.txt 
rm -f result-231.txt
echo "fi 1 0 33 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-231.txt 
rm -f result-232.txt
echo "fi 1 0 33 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-232.txt 
rm -f result-233.txt
echo "fi 1 0 33 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-233.txt 
rm -f result-234.txt
echo "fi 1 0 33 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-234.txt 
rm -f result-235.txt
echo "fi 1 0 33 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-235.txt 
rm -f result-236.txt
echo "fi 1 0 33 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-236.txt 
rm -f result-237.txt
echo "fi 1 0 33 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-237.txt 
rm -f result-238.txt
echo "fi 1 0 34 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-238.txt 
rm -f result-239.txt
echo "fi 1 0 34 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-239.txt 
rm -f result-240.txt
echo "fi 1 0 34 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-240.txt 
rm -f result-241.txt
echo "fi 1 0 34 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-241.txt 
rm -f result-242.txt
echo "fi 1 0 34 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-242.txt 
rm -f result-243.txt
echo "fi 1 0 34 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-243.txt 
rm -f result-244.txt
echo "fi 1 0 34 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-244.txt 
rm -f result-245.txt
echo "fi 1 0 35 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-245.txt 
rm -f result-246.txt
echo "fi 1 0 35 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-246.txt 
rm -f result-247.txt
echo "fi 1 0 35 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-247.txt 
rm -f result-248.txt
echo "fi 1 0 35 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-248.txt 
rm -f result-249.txt
echo "fi 1 0 35 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-249.txt 
rm -f result-250.txt
echo "fi 1 0 35 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-250.txt 
rm -f result-251.txt
echo "fi 1 0 35 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-251.txt 
rm -f result-252.txt
echo "fi 1 0 36 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-252.txt 
rm -f result-253.txt
echo "fi 1 0 36 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-253.txt 
rm -f result-254.txt
echo "fi 1 0 36 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-254.txt 
rm -f result-255.txt
echo "fi 1 0 36 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-255.txt 
rm -f result-256.txt
echo "fi 1 0 36 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-256.txt 
rm -f result-257.txt
echo "fi 1 0 36 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-257.txt 
rm -f result-258.txt
echo "fi 1 0 36 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-258.txt 
rm -f result-259.txt
echo "fi 1 0 45 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-259.txt 
rm -f result-260.txt
echo "fi 1 0 45 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-260.txt 
rm -f result-261.txt
echo "fi 1 0 45 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-261.txt 
rm -f result-262.txt
echo "fi 1 0 45 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-262.txt 
rm -f result-263.txt
echo "fi 1 0 45 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-263.txt 
rm -f result-264.txt
echo "fi 1 0 45 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-264.txt 
rm -f result-265.txt
echo "fi 1 0 45 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-265.txt 
rm -f result-266.txt
echo "fi 1 0 46 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-266.txt 
rm -f result-267.txt
echo "fi 1 0 46 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-267.txt 
rm -f result-268.txt
echo "fi 1 0 46 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-268.txt 
rm -f result-269.txt
echo "fi 1 0 46 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-269.txt 
rm -f result-270.txt
echo "fi 1 0 46 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-270.txt 
rm -f result-271.txt
echo "fi 1 0 46 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-271.txt 
rm -f result-272.txt
echo "fi 1 0 46 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-272.txt 
rm -f result-273.txt
echo "fi 1 0 47 127 0x80000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-273.txt 
rm -f result-274.txt
echo "fi 1 0 47 127 0x40000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-274.txt 
rm -f result-275.txt
echo "fi 1 0 47 127 0x08000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-275.txt 
rm -f result-276.txt
echo "fi 1 0 47 127 0x00800000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-276.txt 
rm -f result-277.txt
echo "fi 1 0 47 127 0x00400000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-277.txt 
rm -f result-278.txt
echo "fi 1 0 47 127 0x00001000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-278.txt 
rm -f result-279.txt
echo "fi 1 0 47 127 0x00000001 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-279.txt 
rm -f result-280.txt
echo "fi 1 0 48 127 0x80000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-280.txt 
rm -f result-281.txt
echo "fi 1 0 48 127 0x40000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-281.txt 
rm -f result-282.txt
echo "fi 1 0 48 127 0x08000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-282.txt 
rm -f result-283.txt
echo "fi 1 0 48 127 0x00800000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-283.txt 
rm -f result-284.txt
echo "fi 1 0 48 127 0x00400000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-284.txt 
rm -f result-285.txt
echo "fi 1 0 48 127 0x00001000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-285.txt 
rm -f result-286.txt
echo "fi 1 0 48 127 0x00000001 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-286.txt 
rm -f result-287.txt
echo "fi 1 0 49 127 0x80000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-287.txt 
rm -f result-288.txt
echo "fi 1 0 49 127 0x40000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-288.txt 
rm -f result-289.txt
echo "fi 1 0 49 127 0x08000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-289.txt 
rm -f result-290.txt
echo "fi 1 0 49 127 0x00800000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-290.txt 
rm -f result-291.txt
echo "fi 1 0 49 127 0x00400000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-291.txt 
rm -f result-292.txt
echo "fi 1 0 49 127 0x00001000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-292.txt 
rm -f result-293.txt
echo "fi 1 0 49 127 0x00000001 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-293.txt 
rm -f result-294.txt
echo "fi 1 0 50 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-294.txt 
rm -f result-295.txt
echo "fi 1 0 50 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-295.txt 
rm -f result-296.txt
echo "fi 1 0 50 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-296.txt 
rm -f result-297.txt
echo "fi 1 0 50 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-297.txt 
rm -f result-298.txt
echo "fi 1 0 50 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-298.txt 
rm -f result-299.txt
echo "fi 1 0 50 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-299.txt 
rm -f result-300.txt
echo "fi 1 0 50 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-300.txt 
rm -f result-301.txt
echo "fi 1 0 51 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-301.txt 
rm -f result-302.txt
echo "fi 1 0 51 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-302.txt 
rm -f result-303.txt
echo "fi 1 0 51 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-303.txt 
rm -f result-304.txt
echo "fi 1 0 51 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-304.txt 
rm -f result-305.txt
echo "fi 1 0 51 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-305.txt 
rm -f result-306.txt
echo "fi 1 0 51 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-306.txt 
rm -f result-307.txt
echo "fi 1 0 51 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-307.txt 
rm -f result-308.txt
echo "fi 1 0 52 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-308.txt 
rm -f result-309.txt
echo "fi 1 0 52 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-309.txt 
rm -f result-310.txt
echo "fi 1 0 52 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-310.txt 
rm -f result-311.txt
echo "fi 1 0 52 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-311.txt 
rm -f result-312.txt
echo "fi 1 0 52 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-312.txt 
rm -f result-313.txt
echo "fi 1 0 52 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-313.txt 
rm -f result-314.txt
echo "fi 1 0 52 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-314.txt 
rm -f result-315.txt
echo "fi 1 0 53 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-315.txt 
rm -f result-316.txt
echo "fi 1 0 53 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-316.txt 
rm -f result-317.txt
echo "fi 1 0 53 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-317.txt 
rm -f result-318.txt
echo "fi 1 0 53 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-318.txt 
rm -f result-319.txt
echo "fi 1 0 53 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-319.txt 
rm -f result-320.txt
echo "fi 1 0 53 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-320.txt 
rm -f result-321.txt
echo "fi 1 0 53 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-321.txt 
rm -f result-322.txt
echo "fi 1 0 54 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-322.txt 
rm -f result-323.txt
echo "fi 1 0 54 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-323.txt 
rm -f result-324.txt
echo "fi 1 0 54 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-324.txt 
rm -f result-325.txt
echo "fi 1 0 54 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-325.txt 
rm -f result-326.txt
echo "fi 1 0 54 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-326.txt 
rm -f result-327.txt
echo "fi 1 0 54 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-327.txt 
rm -f result-328.txt
echo "fi 1 0 54 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-328.txt 
rm -f result-329.txt
echo "fi 1 0 55 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-329.txt 
rm -f result-330.txt
echo "fi 1 0 55 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-330.txt 
rm -f result-331.txt
echo "fi 1 0 55 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-331.txt 
rm -f result-332.txt
echo "fi 1 0 55 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-332.txt 
rm -f result-333.txt
echo "fi 1 0 55 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-333.txt 
rm -f result-334.txt
echo "fi 1 0 55 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-334.txt 
rm -f result-335.txt
echo "fi 1 0 55 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-335.txt 
rm -f result-336.txt
echo "fi 1 0 56 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-336.txt 
rm -f result-337.txt
echo "fi 1 0 56 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-337.txt 
rm -f result-338.txt
echo "fi 1 0 56 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-338.txt 
rm -f result-339.txt
echo "fi 1 0 56 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-339.txt 
rm -f result-340.txt
echo "fi 1 0 56 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-340.txt 
rm -f result-341.txt
echo "fi 1 0 56 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-341.txt 
rm -f result-342.txt
echo "fi 1 0 56 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-342.txt 
rm -f result-343.txt
echo "fi 1 0 57 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-343.txt 
rm -f result-344.txt
echo "fi 1 0 57 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-344.txt 
rm -f result-345.txt
echo "fi 1 0 57 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-345.txt 
rm -f result-346.txt
echo "fi 1 0 57 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-346.txt 
rm -f result-347.txt
echo "fi 1 0 57 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-347.txt 
rm -f result-348.txt
echo "fi 1 0 57 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-348.txt 
rm -f result-349.txt
echo "fi 1 0 57 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-349.txt 
rm -f result-350.txt
echo "fi 1 0 58 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-350.txt 
rm -f result-351.txt
echo "fi 1 0 58 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-351.txt 
rm -f result-352.txt
echo "fi 1 0 58 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-352.txt 
rm -f result-353.txt
echo "fi 1 0 58 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-353.txt 
rm -f result-354.txt
echo "fi 1 0 58 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-354.txt 
rm -f result-355.txt
echo "fi 1 0 58 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-355.txt 
rm -f result-356.txt
echo "fi 1 0 58 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-356.txt 
rm -f result-357.txt
echo "fi 1 0 59 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-357.txt 
rm -f result-358.txt
echo "fi 1 0 59 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-358.txt 
rm -f result-359.txt
echo "fi 1 0 59 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-359.txt 
rm -f result-360.txt
echo "fi 1 0 59 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-360.txt 
rm -f result-361.txt
echo "fi 1 0 59 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-361.txt 
rm -f result-362.txt
echo "fi 1 0 59 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-362.txt 
rm -f result-363.txt
echo "fi 1 0 59 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-363.txt 
rm -f result-364.txt
echo "fi 1 0 60 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-364.txt 
rm -f result-365.txt
echo "fi 1 0 60 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-365.txt 
rm -f result-366.txt
echo "fi 1 0 60 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-366.txt 
rm -f result-367.txt
echo "fi 1 0 60 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-367.txt 
rm -f result-368.txt
echo "fi 1 0 60 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-368.txt 
rm -f result-369.txt
echo "fi 1 0 60 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-369.txt 
rm -f result-370.txt
echo "fi 1 0 60 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-370.txt 
rm -f result-371.txt
echo "fi 1 0 61 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-371.txt 
rm -f result-372.txt
echo "fi 1 0 61 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-372.txt 
rm -f result-373.txt
echo "fi 1 0 61 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-373.txt 
rm -f result-374.txt
echo "fi 1 0 61 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-374.txt 
rm -f result-375.txt
echo "fi 1 0 61 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-375.txt 
rm -f result-376.txt
echo "fi 1 0 61 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-376.txt 
rm -f result-377.txt
echo "fi 1 0 61 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-377.txt 
rm -f result-378.txt
echo "fi 1 0 62 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-378.txt 
rm -f result-379.txt
echo "fi 1 0 62 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-379.txt 
rm -f result-380.txt
echo "fi 1 0 62 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-380.txt 
rm -f result-381.txt
echo "fi 1 0 62 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-381.txt 
rm -f result-382.txt
echo "fi 1 0 62 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-382.txt 
rm -f result-383.txt
echo "fi 1 0 62 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-383.txt 
rm -f result-384.txt
echo "fi 1 0 62 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-384.txt 
rm -f result-385.txt
echo "fi 1 0 63 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-385.txt 
rm -f result-386.txt
echo "fi 1 0 63 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-386.txt 
rm -f result-387.txt
echo "fi 1 0 63 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-387.txt 
rm -f result-388.txt
echo "fi 1 0 63 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-388.txt 
rm -f result-389.txt
echo "fi 1 0 63 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-389.txt 
rm -f result-390.txt
echo "fi 1 0 63 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-390.txt 
rm -f result-391.txt
echo "fi 1 0 63 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-391.txt 
rm -f result-392.txt
echo "fi 1 0 64 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-392.txt 
rm -f result-393.txt
echo "fi 1 0 64 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-393.txt 
rm -f result-394.txt
echo "fi 1 0 64 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-394.txt 
rm -f result-395.txt
echo "fi 1 0 64 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-395.txt 
rm -f result-396.txt
echo "fi 1 0 64 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-396.txt 
rm -f result-397.txt
echo "fi 1 0 64 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-397.txt 
rm -f result-398.txt
echo "fi 1 0 64 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-398.txt 
rm -f result-399.txt
echo "fi 1 0 65 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-399.txt 
rm -f result-400.txt
echo "fi 1 0 65 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-400.txt 
rm -f result-401.txt
echo "fi 1 0 65 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-401.txt 
rm -f result-402.txt
echo "fi 1 0 65 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-402.txt 
rm -f result-403.txt
echo "fi 1 0 65 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-403.txt 
rm -f result-404.txt
echo "fi 1 0 65 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-404.txt 
rm -f result-405.txt
echo "fi 1 0 65 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-405.txt 
rm -f result-406.txt
echo "fi 1 0 66 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-406.txt 
rm -f result-407.txt
echo "fi 1 0 66 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-407.txt 
rm -f result-408.txt
echo "fi 1 0 66 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-408.txt 
rm -f result-409.txt
echo "fi 1 0 66 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-409.txt 
rm -f result-410.txt
echo "fi 1 0 66 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-410.txt 
rm -f result-411.txt
echo "fi 1 0 66 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-411.txt 
rm -f result-412.txt
echo "fi 1 0 66 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-412.txt 
rm -f result-413.txt
echo "fi 1 0 67 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-413.txt 
rm -f result-414.txt
echo "fi 1 0 67 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-414.txt 
rm -f result-415.txt
echo "fi 1 0 67 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-415.txt 
rm -f result-416.txt
echo "fi 1 0 67 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-416.txt 
rm -f result-417.txt
echo "fi 1 0 67 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-417.txt 
rm -f result-418.txt
echo "fi 1 0 67 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-418.txt 
rm -f result-419.txt
echo "fi 1 0 67 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-419.txt 
rm -f result-420.txt
echo "fi 1 0 68 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-420.txt 
rm -f result-421.txt
echo "fi 1 0 68 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-421.txt 
rm -f result-422.txt
echo "fi 1 0 68 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-422.txt 
rm -f result-423.txt
echo "fi 1 0 68 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-423.txt 
rm -f result-424.txt
echo "fi 1 0 68 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-424.txt 
rm -f result-425.txt
echo "fi 1 0 68 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-425.txt 
rm -f result-426.txt
echo "fi 1 0 68 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-426.txt 
rm -f result-427.txt
echo "fi 1 0 69 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-427.txt 
rm -f result-428.txt
echo "fi 1 0 69 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-428.txt 
rm -f result-429.txt
echo "fi 1 0 69 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-429.txt 
rm -f result-430.txt
echo "fi 1 0 69 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-430.txt 
rm -f result-431.txt
echo "fi 1 0 69 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-431.txt 
rm -f result-432.txt
echo "fi 1 0 69 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-432.txt 
rm -f result-433.txt
echo "fi 1 0 69 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-433.txt 
rm -f result-434.txt
echo "fi 1 0 70 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-434.txt 
rm -f result-435.txt
echo "fi 1 0 70 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-435.txt 
rm -f result-436.txt
echo "fi 1 0 70 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-436.txt 
rm -f result-437.txt
echo "fi 1 0 70 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-437.txt 
rm -f result-438.txt
echo "fi 1 0 70 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-438.txt 
rm -f result-439.txt
echo "fi 1 0 70 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-439.txt 
rm -f result-440.txt
echo "fi 1 0 70 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-440.txt 
rm -f result-441.txt
echo "fi 1 0 71 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-441.txt 
rm -f result-442.txt
echo "fi 1 0 71 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-442.txt 
rm -f result-443.txt
echo "fi 1 0 71 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-443.txt 
rm -f result-444.txt
echo "fi 1 0 71 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-444.txt 
rm -f result-445.txt
echo "fi 1 0 71 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-445.txt 
rm -f result-446.txt
echo "fi 1 0 71 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-446.txt 
rm -f result-447.txt
echo "fi 1 0 71 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-447.txt 
rm -f result-448.txt
echo "fi 1 0 72 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-448.txt 
rm -f result-449.txt
echo "fi 1 0 72 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-449.txt 
rm -f result-450.txt
echo "fi 1 0 72 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-450.txt 
rm -f result-451.txt
echo "fi 1 0 72 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-451.txt 
rm -f result-452.txt
echo "fi 1 0 72 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-452.txt 
rm -f result-453.txt
echo "fi 1 0 72 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-453.txt 
rm -f result-454.txt
echo "fi 1 0 72 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-454.txt 
rm -f result-455.txt
echo "fi 1 0 73 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-455.txt 
rm -f result-456.txt
echo "fi 1 0 73 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-456.txt 
rm -f result-457.txt
echo "fi 1 0 73 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-457.txt 
rm -f result-458.txt
echo "fi 1 0 73 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-458.txt 
rm -f result-459.txt
echo "fi 1 0 73 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-459.txt 
rm -f result-460.txt
echo "fi 1 0 73 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-460.txt 
rm -f result-461.txt
echo "fi 1 0 73 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-461.txt 
rm -f result-462.txt
echo "fi 1 0 74 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-462.txt 
rm -f result-463.txt
echo "fi 1 0 74 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-463.txt 
rm -f result-464.txt
echo "fi 1 0 74 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-464.txt 
rm -f result-465.txt
echo "fi 1 0 74 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-465.txt 
rm -f result-466.txt
echo "fi 1 0 74 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-466.txt 
rm -f result-467.txt
echo "fi 1 0 74 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-467.txt 
rm -f result-468.txt
echo "fi 1 0 74 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-468.txt 
rm -f result-469.txt
echo "fi 1 0 75 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-469.txt 
rm -f result-470.txt
echo "fi 1 0 75 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-470.txt 
rm -f result-471.txt
echo "fi 1 0 75 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-471.txt 
rm -f result-472.txt
echo "fi 1 0 75 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-472.txt 
rm -f result-473.txt
echo "fi 1 0 75 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-473.txt 
rm -f result-474.txt
echo "fi 1 0 75 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-474.txt 
rm -f result-475.txt
echo "fi 1 0 75 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-475.txt 
rm -f result-476.txt
echo "fi 1 0 76 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-476.txt 
rm -f result-477.txt
echo "fi 1 0 76 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-477.txt 
rm -f result-478.txt
echo "fi 1 0 76 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-478.txt 
rm -f result-479.txt
echo "fi 1 0 76 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-479.txt 
rm -f result-480.txt
echo "fi 1 0 76 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-480.txt 
rm -f result-481.txt
echo "fi 1 0 76 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-481.txt 
rm -f result-482.txt
echo "fi 1 0 76 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-482.txt 
rm -f result-483.txt
echo "fi 1 0 77 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-483.txt 
rm -f result-484.txt
echo "fi 1 0 77 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-484.txt 
rm -f result-485.txt
echo "fi 1 0 77 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-485.txt 
rm -f result-486.txt
echo "fi 1 0 77 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-486.txt 
rm -f result-487.txt
echo "fi 1 0 77 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-487.txt 
rm -f result-488.txt
echo "fi 1 0 77 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-488.txt 
rm -f result-489.txt
echo "fi 1 0 77 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-489.txt 
rm -f result-490.txt
echo "fi 1 0 78 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-490.txt 
rm -f result-491.txt
echo "fi 1 0 78 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-491.txt 
rm -f result-492.txt
echo "fi 1 0 78 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-492.txt 
rm -f result-493.txt
echo "fi 1 0 78 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-493.txt 
rm -f result-494.txt
echo "fi 1 0 78 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-494.txt 
rm -f result-495.txt
echo "fi 1 0 78 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-495.txt 
rm -f result-496.txt
echo "fi 1 0 78 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-496.txt 
rm -f result-497.txt
echo "fi 1 0 79 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-497.txt 
rm -f result-498.txt
echo "fi 1 0 79 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-498.txt 
rm -f result-499.txt
echo "fi 1 0 79 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-499.txt 
rm -f result-500.txt
echo "fi 1 0 79 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-500.txt 
rm -f result-501.txt
echo "fi 1 0 79 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-501.txt 
rm -f result-502.txt
echo "fi 1 0 79 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-502.txt 
rm -f result-503.txt
echo "fi 1 0 79 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-503.txt 
rm -f result-504.txt
echo "fi 1 0 80 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-504.txt 
rm -f result-505.txt
echo "fi 1 0 80 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-505.txt 
rm -f result-506.txt
echo "fi 1 0 80 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-506.txt 
rm -f result-507.txt
echo "fi 1 0 80 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-507.txt 
rm -f result-508.txt
echo "fi 1 0 80 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-508.txt 
rm -f result-509.txt
echo "fi 1 0 80 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-509.txt 
rm -f result-510.txt
echo "fi 1 0 80 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-510.txt 
rm -f result-511.txt
echo "fi 1 0 81 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-511.txt 
rm -f result-512.txt
echo "fi 1 0 81 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-512.txt 
rm -f result-513.txt
echo "fi 1 0 81 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-513.txt 
rm -f result-514.txt
echo "fi 1 0 81 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-514.txt 
rm -f result-515.txt
echo "fi 1 0 81 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-515.txt 
rm -f result-516.txt
echo "fi 1 0 81 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-516.txt 
rm -f result-517.txt
echo "fi 1 0 81 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-517.txt 
rm -f result-518.txt
echo "fi 1 0 82 0 0x80000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-518.txt 
rm -f result-519.txt
echo "fi 1 0 82 0 0x40000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-519.txt 
rm -f result-520.txt
echo "fi 1 0 82 0 0x08000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-520.txt 
rm -f result-521.txt
echo "fi 1 0 82 0 0x00800000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-521.txt 
rm -f result-522.txt
echo "fi 1 0 82 0 0x00400000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-522.txt 
rm -f result-523.txt
echo "fi 1 0 82 0 0x00001000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-523.txt 
rm -f result-524.txt
echo "fi 1 0 82 0 0x00000001 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-524.txt 
rm -f result-525.txt
echo "fi 1 0 83 0 0x80000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-525.txt 
rm -f result-526.txt
echo "fi 1 0 83 0 0x40000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-526.txt 
rm -f result-527.txt
echo "fi 1 0 83 0 0x08000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-527.txt 
rm -f result-528.txt
echo "fi 1 0 83 0 0x00800000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-528.txt 
rm -f result-529.txt
echo "fi 1 0 83 0 0x00400000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-529.txt 
rm -f result-530.txt
echo "fi 1 0 83 0 0x00001000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-530.txt 
rm -f result-531.txt
echo "fi 1 0 83 0 0x00000001 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-531.txt 
rm -f result-532.txt
echo "fi 1 1 7 0 0x80000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-532.txt 
rm -f result-533.txt
echo "fi 1 1 7 0 0x40000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-533.txt 
rm -f result-534.txt
echo "fi 1 1 7 0 0x08000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-534.txt 
rm -f result-535.txt
echo "fi 1 1 7 0 0x00800000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-535.txt 
rm -f result-536.txt
echo "fi 1 1 7 0 0x00400000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-536.txt 
rm -f result-537.txt
echo "fi 1 1 7 0 0x00001000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-537.txt 
rm -f result-538.txt
echo "fi 1 1 7 0 0x00000001 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-538.txt 
rm -f result-539.txt
echo "fi 1 1 8 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-539.txt 
rm -f result-540.txt
echo "fi 1 1 8 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-540.txt 
rm -f result-541.txt
echo "fi 1 1 8 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-541.txt 
rm -f result-542.txt
echo "fi 1 1 8 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-542.txt 
rm -f result-543.txt
echo "fi 1 1 8 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-543.txt 
rm -f result-544.txt
echo "fi 1 1 8 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-544.txt 
rm -f result-545.txt
echo "fi 1 1 8 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-545.txt 
rm -f result-546.txt
echo "fi 1 1 9 0 0x80000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-546.txt 
rm -f result-547.txt
echo "fi 1 1 9 0 0x40000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-547.txt 
rm -f result-548.txt
echo "fi 1 1 9 0 0x08000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-548.txt 
rm -f result-549.txt
echo "fi 1 1 9 0 0x00800000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-549.txt 
rm -f result-550.txt
echo "fi 1 1 9 0 0x00400000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-550.txt 
rm -f result-551.txt
echo "fi 1 1 9 0 0x00001000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-551.txt 
rm -f result-552.txt
echo "fi 1 1 9 0 0x00000001 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-552.txt 
rm -f result-553.txt
echo "fi 1 1 10 0 0x80000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-553.txt 
rm -f result-554.txt
echo "fi 1 1 10 0 0x40000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-554.txt 
rm -f result-555.txt
echo "fi 1 1 10 0 0x08000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-555.txt 
rm -f result-556.txt
echo "fi 1 1 10 0 0x00800000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-556.txt 
rm -f result-557.txt
echo "fi 1 1 10 0 0x00400000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-557.txt 
rm -f result-558.txt
echo "fi 1 1 10 0 0x00001000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-558.txt 
rm -f result-559.txt
echo "fi 1 1 10 0 0x00000001 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-559.txt 
rm -f result-560.txt
echo "fi 1 1 11 0 0x80000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-560.txt 
rm -f result-561.txt
echo "fi 1 1 11 0 0x40000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-561.txt 
rm -f result-562.txt
echo "fi 1 1 11 0 0x08000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-562.txt 
rm -f result-563.txt
echo "fi 1 1 11 0 0x00800000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-563.txt 
rm -f result-564.txt
echo "fi 1 1 11 0 0x00400000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-564.txt 
rm -f result-565.txt
echo "fi 1 1 11 0 0x00001000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-565.txt 
rm -f result-566.txt
echo "fi 1 1 11 0 0x00000001 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-566.txt 
rm -f result-567.txt
echo "fi 1 1 12 0 0x80000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-567.txt 
rm -f result-568.txt
echo "fi 1 1 12 0 0x40000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-568.txt 
rm -f result-569.txt
echo "fi 1 1 12 0 0x08000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-569.txt 
rm -f result-570.txt
echo "fi 1 1 12 0 0x00800000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-570.txt 
rm -f result-571.txt
echo "fi 1 1 12 0 0x00400000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-571.txt 
rm -f result-572.txt
echo "fi 1 1 12 0 0x00001000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-572.txt 
rm -f result-573.txt
echo "fi 1 1 12 0 0x00000001 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-573.txt 
rm -f result-574.txt
echo "fi 1 1 13 0 0x80000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-574.txt 
rm -f result-575.txt
echo "fi 1 1 13 0 0x40000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-575.txt 
rm -f result-576.txt
echo "fi 1 1 13 0 0x08000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-576.txt 
rm -f result-577.txt
echo "fi 1 1 13 0 0x00800000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-577.txt 
rm -f result-578.txt
echo "fi 1 1 13 0 0x00400000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-578.txt 
rm -f result-579.txt
echo "fi 1 1 13 0 0x00001000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-579.txt 
rm -f result-580.txt
echo "fi 1 1 13 0 0x00000001 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-580.txt 
rm -f result-581.txt
echo "fi 1 1 21 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-581.txt 
rm -f result-582.txt
echo "fi 1 1 21 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-582.txt 
rm -f result-583.txt
echo "fi 1 1 21 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-583.txt 
rm -f result-584.txt
echo "fi 1 1 21 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-584.txt 
rm -f result-585.txt
echo "fi 1 1 21 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-585.txt 
rm -f result-586.txt
echo "fi 1 1 21 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-586.txt 
rm -f result-587.txt
echo "fi 1 1 21 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-587.txt 
rm -f result-588.txt
echo "fi 1 1 22 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-588.txt 
rm -f result-589.txt
echo "fi 1 1 22 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-589.txt 
rm -f result-590.txt
echo "fi 1 1 22 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-590.txt 
rm -f result-591.txt
echo "fi 1 1 22 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-591.txt 
rm -f result-592.txt
echo "fi 1 1 22 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-592.txt 
rm -f result-593.txt
echo "fi 1 1 22 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-593.txt 
rm -f result-594.txt
echo "fi 1 1 22 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-594.txt 
rm -f result-595.txt
echo "fi 1 1 23 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-595.txt 
rm -f result-596.txt
echo "fi 1 1 23 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-596.txt 
rm -f result-597.txt
echo "fi 1 1 23 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-597.txt 
rm -f result-598.txt
echo "fi 1 1 23 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-598.txt 
rm -f result-599.txt
echo "fi 1 1 23 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-599.txt 
rm -f result-600.txt
echo "fi 1 1 23 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-600.txt 
rm -f result-601.txt
echo "fi 1 1 23 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-601.txt 
rm -f result-602.txt
echo "fi 1 1 24 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-602.txt 
rm -f result-603.txt
echo "fi 1 1 24 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-603.txt 
rm -f result-604.txt
echo "fi 1 1 24 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-604.txt 
rm -f result-605.txt
echo "fi 1 1 24 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-605.txt 
rm -f result-606.txt
echo "fi 1 1 24 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-606.txt 
rm -f result-607.txt
echo "fi 1 1 24 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-607.txt 
rm -f result-608.txt
echo "fi 1 1 24 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-608.txt 
rm -f result-609.txt
echo "fi 1 1 25 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-609.txt 
rm -f result-610.txt
echo "fi 1 1 25 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-610.txt 
rm -f result-611.txt
echo "fi 1 1 25 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-611.txt 
rm -f result-612.txt
echo "fi 1 1 25 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-612.txt 
rm -f result-613.txt
echo "fi 1 1 25 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-613.txt 
rm -f result-614.txt
echo "fi 1 1 25 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-614.txt 
rm -f result-615.txt
echo "fi 1 1 25 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-615.txt 
rm -f result-616.txt
echo "fi 1 1 26 0 0x80000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-616.txt 
rm -f result-617.txt
echo "fi 1 1 26 0 0x40000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-617.txt 
rm -f result-618.txt
echo "fi 1 1 26 0 0x08000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-618.txt 
rm -f result-619.txt
echo "fi 1 1 26 0 0x00800000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-619.txt 
rm -f result-620.txt
echo "fi 1 1 26 0 0x00400000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-620.txt 
rm -f result-621.txt
echo "fi 1 1 26 0 0x00001000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-621.txt 
rm -f result-622.txt
echo "fi 1 1 26 0 0x00000001 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-622.txt 
rm -f result-623.txt
echo "fi 1 1 27 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-623.txt 
rm -f result-624.txt
echo "fi 1 1 27 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-624.txt 
rm -f result-625.txt
echo "fi 1 1 27 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-625.txt 
rm -f result-626.txt
echo "fi 1 1 27 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-626.txt 
rm -f result-627.txt
echo "fi 1 1 27 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-627.txt 
rm -f result-628.txt
echo "fi 1 1 27 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-628.txt 
rm -f result-629.txt
echo "fi 1 1 27 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-629.txt 
rm -f result-630.txt
echo "fi 1 1 28 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-630.txt 
rm -f result-631.txt
echo "fi 1 1 28 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-631.txt 
rm -f result-632.txt
echo "fi 1 1 28 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-632.txt 
rm -f result-633.txt
echo "fi 1 1 28 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-633.txt 
rm -f result-634.txt
echo "fi 1 1 28 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-634.txt 
rm -f result-635.txt
echo "fi 1 1 28 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-635.txt 
rm -f result-636.txt
echo "fi 1 1 28 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-636.txt 
rm -f result-637.txt
echo "fi 1 1 29 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-637.txt 
rm -f result-638.txt
echo "fi 1 1 29 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-638.txt 
rm -f result-639.txt
echo "fi 1 1 29 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-639.txt 
rm -f result-640.txt
echo "fi 1 1 29 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-640.txt 
rm -f result-641.txt
echo "fi 1 1 29 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-641.txt 
rm -f result-642.txt
echo "fi 1 1 29 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-642.txt 
rm -f result-643.txt
echo "fi 1 1 29 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-643.txt 
rm -f result-644.txt
echo "fi 1 1 30 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-644.txt 
rm -f result-645.txt
echo "fi 1 1 30 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-645.txt 
rm -f result-646.txt
echo "fi 1 1 30 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-646.txt 
rm -f result-647.txt
echo "fi 1 1 30 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-647.txt 
rm -f result-648.txt
echo "fi 1 1 30 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-648.txt 
rm -f result-649.txt
echo "fi 1 1 30 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-649.txt 
rm -f result-650.txt
echo "fi 1 1 30 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-650.txt 
rm -f result-651.txt
echo "fi 1 1 31 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-651.txt 
rm -f result-652.txt
echo "fi 1 1 31 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-652.txt 
rm -f result-653.txt
echo "fi 1 1 31 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-653.txt 
rm -f result-654.txt
echo "fi 1 1 31 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-654.txt 
rm -f result-655.txt
echo "fi 1 1 31 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-655.txt 
rm -f result-656.txt
echo "fi 1 1 31 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-656.txt 
rm -f result-657.txt
echo "fi 1 1 31 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-657.txt 
rm -f result-658.txt
echo "fi 1 1 32 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-658.txt 
rm -f result-659.txt
echo "fi 1 1 32 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-659.txt 
rm -f result-660.txt
echo "fi 1 1 32 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-660.txt 
rm -f result-661.txt
echo "fi 1 1 32 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-661.txt 
rm -f result-662.txt
echo "fi 1 1 32 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-662.txt 
rm -f result-663.txt
echo "fi 1 1 32 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-663.txt 
rm -f result-664.txt
echo "fi 1 1 32 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-664.txt 
rm -f result-665.txt
echo "fi 1 1 33 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-665.txt 
rm -f result-666.txt
echo "fi 1 1 33 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-666.txt 
rm -f result-667.txt
echo "fi 1 1 33 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-667.txt 
rm -f result-668.txt
echo "fi 1 1 33 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-668.txt 
rm -f result-669.txt
echo "fi 1 1 33 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-669.txt 
rm -f result-670.txt
echo "fi 1 1 33 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-670.txt 
rm -f result-671.txt
echo "fi 1 1 33 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-671.txt 
rm -f result-672.txt
echo "fi 1 1 34 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-672.txt 
rm -f result-673.txt
echo "fi 1 1 34 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-673.txt 
rm -f result-674.txt
echo "fi 1 1 34 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-674.txt 
rm -f result-675.txt
echo "fi 1 1 34 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-675.txt 
rm -f result-676.txt
echo "fi 1 1 34 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-676.txt 
rm -f result-677.txt
echo "fi 1 1 34 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-677.txt 
rm -f result-678.txt
echo "fi 1 1 34 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-678.txt 
rm -f result-679.txt
echo "fi 1 1 35 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-679.txt 
rm -f result-680.txt
echo "fi 1 1 35 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-680.txt 
rm -f result-681.txt
echo "fi 1 1 35 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-681.txt 
rm -f result-682.txt
echo "fi 1 1 35 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-682.txt 
rm -f result-683.txt
echo "fi 1 1 35 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-683.txt 
rm -f result-684.txt
echo "fi 1 1 35 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-684.txt 
rm -f result-685.txt
echo "fi 1 1 35 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-685.txt 
rm -f result-686.txt
echo "fi 1 1 36 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-686.txt 
rm -f result-687.txt
echo "fi 1 1 36 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-687.txt 
rm -f result-688.txt
echo "fi 1 1 36 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-688.txt 
rm -f result-689.txt
echo "fi 1 1 36 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-689.txt 
rm -f result-690.txt
echo "fi 1 1 36 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-690.txt 
rm -f result-691.txt
echo "fi 1 1 36 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-691.txt 
rm -f result-692.txt
echo "fi 1 1 36 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-692.txt 
rm -f result-693.txt
echo "fi 1 1 45 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-693.txt 
rm -f result-694.txt
echo "fi 1 1 45 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-694.txt 
rm -f result-695.txt
echo "fi 1 1 45 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-695.txt 
rm -f result-696.txt
echo "fi 1 1 45 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-696.txt 
rm -f result-697.txt
echo "fi 1 1 45 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-697.txt 
rm -f result-698.txt
echo "fi 1 1 45 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-698.txt 
rm -f result-699.txt
echo "fi 1 1 45 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-699.txt 
rm -f result-700.txt
echo "fi 1 1 46 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-700.txt 
rm -f result-701.txt
echo "fi 1 1 46 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-701.txt 
rm -f result-702.txt
echo "fi 1 1 46 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-702.txt 
rm -f result-703.txt
echo "fi 1 1 46 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-703.txt 
rm -f result-704.txt
echo "fi 1 1 46 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-704.txt 
rm -f result-705.txt
echo "fi 1 1 46 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-705.txt 
rm -f result-706.txt
echo "fi 1 1 46 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-706.txt 
rm -f result-707.txt
echo "fi 1 1 47 127 0x80000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-707.txt 
rm -f result-708.txt
echo "fi 1 1 47 127 0x40000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-708.txt 
rm -f result-709.txt
echo "fi 1 1 47 127 0x08000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-709.txt 
rm -f result-710.txt
echo "fi 1 1 47 127 0x00800000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-710.txt 
rm -f result-711.txt
echo "fi 1 1 47 127 0x00400000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-711.txt 
rm -f result-712.txt
echo "fi 1 1 47 127 0x00001000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-712.txt 
rm -f result-713.txt
echo "fi 1 1 47 127 0x00000001 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-713.txt 
rm -f result-714.txt
echo "fi 1 1 48 127 0x80000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-714.txt 
rm -f result-715.txt
echo "fi 1 1 48 127 0x40000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-715.txt 
rm -f result-716.txt
echo "fi 1 1 48 127 0x08000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-716.txt 
rm -f result-717.txt
echo "fi 1 1 48 127 0x00800000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-717.txt 
rm -f result-718.txt
echo "fi 1 1 48 127 0x00400000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-718.txt 
rm -f result-719.txt
echo "fi 1 1 48 127 0x00001000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-719.txt 
rm -f result-720.txt
echo "fi 1 1 48 127 0x00000001 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-720.txt 
rm -f result-721.txt
echo "fi 1 1 49 127 0x80000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-721.txt 
rm -f result-722.txt
echo "fi 1 1 49 127 0x40000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-722.txt 
rm -f result-723.txt
echo "fi 1 1 49 127 0x08000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-723.txt 
rm -f result-724.txt
echo "fi 1 1 49 127 0x00800000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-724.txt 
rm -f result-725.txt
echo "fi 1 1 49 127 0x00400000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-725.txt 
rm -f result-726.txt
echo "fi 1 1 49 127 0x00001000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-726.txt 
rm -f result-727.txt
echo "fi 1 1 49 127 0x00000001 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-727.txt 
rm -f result-728.txt
echo "fi 1 1 50 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-728.txt 
rm -f result-729.txt
echo "fi 1 1 50 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-729.txt 
rm -f result-730.txt
echo "fi 1 1 50 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-730.txt 
rm -f result-731.txt
echo "fi 1 1 50 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-731.txt 
rm -f result-732.txt
echo "fi 1 1 50 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-732.txt 
rm -f result-733.txt
echo "fi 1 1 50 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-733.txt 
rm -f result-734.txt
echo "fi 1 1 50 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-734.txt 
rm -f result-735.txt
echo "fi 1 1 51 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-735.txt 
rm -f result-736.txt
echo "fi 1 1 51 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-736.txt 
rm -f result-737.txt
echo "fi 1 1 51 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-737.txt 
rm -f result-738.txt
echo "fi 1 1 51 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-738.txt 
rm -f result-739.txt
echo "fi 1 1 51 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-739.txt 
rm -f result-740.txt
echo "fi 1 1 51 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-740.txt 
rm -f result-741.txt
echo "fi 1 1 51 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-741.txt 
rm -f result-742.txt
echo "fi 1 1 52 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-742.txt 
rm -f result-743.txt
echo "fi 1 1 52 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-743.txt 
rm -f result-744.txt
echo "fi 1 1 52 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-744.txt 
rm -f result-745.txt
echo "fi 1 1 52 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-745.txt 
rm -f result-746.txt
echo "fi 1 1 52 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-746.txt 
rm -f result-747.txt
echo "fi 1 1 52 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-747.txt 
rm -f result-748.txt
echo "fi 1 1 52 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-748.txt 
rm -f result-749.txt
echo "fi 1 1 53 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-749.txt 
rm -f result-750.txt
echo "fi 1 1 53 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-750.txt 
rm -f result-751.txt
echo "fi 1 1 53 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-751.txt 
rm -f result-752.txt
echo "fi 1 1 53 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-752.txt 
rm -f result-753.txt
echo "fi 1 1 53 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-753.txt 
rm -f result-754.txt
echo "fi 1 1 53 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-754.txt 
rm -f result-755.txt
echo "fi 1 1 53 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-755.txt 
rm -f result-756.txt
echo "fi 1 1 54 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-756.txt 
rm -f result-757.txt
echo "fi 1 1 54 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-757.txt 
rm -f result-758.txt
echo "fi 1 1 54 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-758.txt 
rm -f result-759.txt
echo "fi 1 1 54 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-759.txt 
rm -f result-760.txt
echo "fi 1 1 54 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-760.txt 
rm -f result-761.txt
echo "fi 1 1 54 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-761.txt 
rm -f result-762.txt
echo "fi 1 1 54 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-762.txt 
rm -f result-763.txt
echo "fi 1 1 55 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-763.txt 
rm -f result-764.txt
echo "fi 1 1 55 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-764.txt 
rm -f result-765.txt
echo "fi 1 1 55 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-765.txt 
rm -f result-766.txt
echo "fi 1 1 55 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-766.txt 
rm -f result-767.txt
echo "fi 1 1 55 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-767.txt 
rm -f result-768.txt
echo "fi 1 1 55 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-768.txt 
rm -f result-769.txt
echo "fi 1 1 55 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-769.txt 
rm -f result-770.txt
echo "fi 1 1 56 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-770.txt 
rm -f result-771.txt
echo "fi 1 1 56 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-771.txt 
rm -f result-772.txt
echo "fi 1 1 56 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-772.txt 
rm -f result-773.txt
echo "fi 1 1 56 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-773.txt 
rm -f result-774.txt
echo "fi 1 1 56 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-774.txt 
rm -f result-775.txt
echo "fi 1 1 56 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-775.txt 
rm -f result-776.txt
echo "fi 1 1 56 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-776.txt 
rm -f result-777.txt
echo "fi 1 1 57 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-777.txt 
rm -f result-778.txt
echo "fi 1 1 57 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-778.txt 
rm -f result-779.txt
echo "fi 1 1 57 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-779.txt 
rm -f result-780.txt
echo "fi 1 1 57 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-780.txt 
rm -f result-781.txt
echo "fi 1 1 57 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-781.txt 
rm -f result-782.txt
echo "fi 1 1 57 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-782.txt 
rm -f result-783.txt
echo "fi 1 1 57 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-783.txt 
rm -f result-784.txt
echo "fi 1 1 58 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-784.txt 
rm -f result-785.txt
echo "fi 1 1 58 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-785.txt 
rm -f result-786.txt
echo "fi 1 1 58 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-786.txt 
rm -f result-787.txt
echo "fi 1 1 58 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-787.txt 
rm -f result-788.txt
echo "fi 1 1 58 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-788.txt 
rm -f result-789.txt
echo "fi 1 1 58 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-789.txt 
rm -f result-790.txt
echo "fi 1 1 58 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-790.txt 
rm -f result-791.txt
echo "fi 1 1 59 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-791.txt 
rm -f result-792.txt
echo "fi 1 1 59 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-792.txt 
rm -f result-793.txt
echo "fi 1 1 59 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-793.txt 
rm -f result-794.txt
echo "fi 1 1 59 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-794.txt 
rm -f result-795.txt
echo "fi 1 1 59 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-795.txt 
rm -f result-796.txt
echo "fi 1 1 59 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-796.txt 
rm -f result-797.txt
echo "fi 1 1 59 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-797.txt 
rm -f result-798.txt
echo "fi 1 1 60 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-798.txt 
rm -f result-799.txt
echo "fi 1 1 60 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-799.txt 
rm -f result-800.txt
echo "fi 1 1 60 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-800.txt 
rm -f result-801.txt
echo "fi 1 1 60 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-801.txt 
rm -f result-802.txt
echo "fi 1 1 60 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-802.txt 
rm -f result-803.txt
echo "fi 1 1 60 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-803.txt 
rm -f result-804.txt
echo "fi 1 1 60 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-804.txt 
rm -f result-805.txt
echo "fi 1 1 61 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-805.txt 
rm -f result-806.txt
echo "fi 1 1 61 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-806.txt 
rm -f result-807.txt
echo "fi 1 1 61 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-807.txt 
rm -f result-808.txt
echo "fi 1 1 61 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-808.txt 
rm -f result-809.txt
echo "fi 1 1 61 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-809.txt 
rm -f result-810.txt
echo "fi 1 1 61 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-810.txt 
rm -f result-811.txt
echo "fi 1 1 61 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-811.txt 
rm -f result-812.txt
echo "fi 1 1 62 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-812.txt 
rm -f result-813.txt
echo "fi 1 1 62 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-813.txt 
rm -f result-814.txt
echo "fi 1 1 62 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-814.txt 
rm -f result-815.txt
echo "fi 1 1 62 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-815.txt 
rm -f result-816.txt
echo "fi 1 1 62 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-816.txt 
rm -f result-817.txt
echo "fi 1 1 62 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-817.txt 
rm -f result-818.txt
echo "fi 1 1 62 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-818.txt 
rm -f result-819.txt
echo "fi 1 1 63 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-819.txt 
rm -f result-820.txt
echo "fi 1 1 63 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-820.txt 
rm -f result-821.txt
echo "fi 1 1 63 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-821.txt 
rm -f result-822.txt
echo "fi 1 1 63 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-822.txt 
rm -f result-823.txt
echo "fi 1 1 63 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-823.txt 
rm -f result-824.txt
echo "fi 1 1 63 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-824.txt 
rm -f result-825.txt
echo "fi 1 1 63 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-825.txt 
rm -f result-826.txt
echo "fi 1 1 64 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-826.txt 
rm -f result-827.txt
echo "fi 1 1 64 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-827.txt 
rm -f result-828.txt
echo "fi 1 1 64 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-828.txt 
rm -f result-829.txt
echo "fi 1 1 64 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-829.txt 
rm -f result-830.txt
echo "fi 1 1 64 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-830.txt 
rm -f result-831.txt
echo "fi 1 1 64 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-831.txt 
rm -f result-832.txt
echo "fi 1 1 64 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-832.txt 
rm -f result-833.txt
echo "fi 1 1 65 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-833.txt 
rm -f result-834.txt
echo "fi 1 1 65 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-834.txt 
rm -f result-835.txt
echo "fi 1 1 65 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-835.txt 
rm -f result-836.txt
echo "fi 1 1 65 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-836.txt 
rm -f result-837.txt
echo "fi 1 1 65 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-837.txt 
rm -f result-838.txt
echo "fi 1 1 65 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-838.txt 
rm -f result-839.txt
echo "fi 1 1 65 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-839.txt 
rm -f result-840.txt
echo "fi 1 1 66 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-840.txt 
rm -f result-841.txt
echo "fi 1 1 66 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-841.txt 
rm -f result-842.txt
echo "fi 1 1 66 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-842.txt 
rm -f result-843.txt
echo "fi 1 1 66 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-843.txt 
rm -f result-844.txt
echo "fi 1 1 66 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-844.txt 
rm -f result-845.txt
echo "fi 1 1 66 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-845.txt 
rm -f result-846.txt
echo "fi 1 1 66 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-846.txt 
rm -f result-847.txt
echo "fi 1 1 67 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-847.txt 
rm -f result-848.txt
echo "fi 1 1 67 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-848.txt 
rm -f result-849.txt
echo "fi 1 1 67 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-849.txt 
rm -f result-850.txt
echo "fi 1 1 67 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-850.txt 
rm -f result-851.txt
echo "fi 1 1 67 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-851.txt 
rm -f result-852.txt
echo "fi 1 1 67 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-852.txt 
rm -f result-853.txt
echo "fi 1 1 67 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-853.txt 
rm -f result-854.txt
echo "fi 1 1 68 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-854.txt 
rm -f result-855.txt
echo "fi 1 1 68 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-855.txt 
rm -f result-856.txt
echo "fi 1 1 68 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-856.txt 
rm -f result-857.txt
echo "fi 1 1 68 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-857.txt 
rm -f result-858.txt
echo "fi 1 1 68 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-858.txt 
rm -f result-859.txt
echo "fi 1 1 68 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-859.txt 
rm -f result-860.txt
echo "fi 1 1 68 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-860.txt 
rm -f result-861.txt
echo "fi 1 1 69 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-861.txt 
rm -f result-862.txt
echo "fi 1 1 69 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-862.txt 
rm -f result-863.txt
echo "fi 1 1 69 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-863.txt 
rm -f result-864.txt
echo "fi 1 1 69 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-864.txt 
rm -f result-865.txt
echo "fi 1 1 69 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-865.txt 
rm -f result-866.txt
echo "fi 1 1 69 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-866.txt 
rm -f result-867.txt
echo "fi 1 1 69 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-867.txt 
rm -f result-868.txt
echo "fi 1 1 70 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-868.txt 
rm -f result-869.txt
echo "fi 1 1 70 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-869.txt 
rm -f result-870.txt
echo "fi 1 1 70 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-870.txt 
rm -f result-871.txt
echo "fi 1 1 70 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-871.txt 
rm -f result-872.txt
echo "fi 1 1 70 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-872.txt 
rm -f result-873.txt
echo "fi 1 1 70 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-873.txt 
rm -f result-874.txt
echo "fi 1 1 70 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-874.txt 
rm -f result-875.txt
echo "fi 1 1 71 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-875.txt 
rm -f result-876.txt
echo "fi 1 1 71 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-876.txt 
rm -f result-877.txt
echo "fi 1 1 71 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-877.txt 
rm -f result-878.txt
echo "fi 1 1 71 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-878.txt 
rm -f result-879.txt
echo "fi 1 1 71 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-879.txt 
rm -f result-880.txt
echo "fi 1 1 71 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-880.txt 
rm -f result-881.txt
echo "fi 1 1 71 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-881.txt 
rm -f result-882.txt
echo "fi 1 1 72 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-882.txt 
rm -f result-883.txt
echo "fi 1 1 72 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-883.txt 
rm -f result-884.txt
echo "fi 1 1 72 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-884.txt 
rm -f result-885.txt
echo "fi 1 1 72 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-885.txt 
rm -f result-886.txt
echo "fi 1 1 72 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-886.txt 
rm -f result-887.txt
echo "fi 1 1 72 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-887.txt 
rm -f result-888.txt
echo "fi 1 1 72 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-888.txt 
rm -f result-889.txt
echo "fi 1 1 73 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-889.txt 
rm -f result-890.txt
echo "fi 1 1 73 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-890.txt 
rm -f result-891.txt
echo "fi 1 1 73 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-891.txt 
rm -f result-892.txt
echo "fi 1 1 73 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-892.txt 
rm -f result-893.txt
echo "fi 1 1 73 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-893.txt 
rm -f result-894.txt
echo "fi 1 1 73 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-894.txt 
rm -f result-895.txt
echo "fi 1 1 73 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-895.txt 
rm -f result-896.txt
echo "fi 1 1 74 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-896.txt 
rm -f result-897.txt
echo "fi 1 1 74 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-897.txt 
rm -f result-898.txt
echo "fi 1 1 74 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-898.txt 
rm -f result-899.txt
echo "fi 1 1 74 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-899.txt 
rm -f result-900.txt
echo "fi 1 1 74 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-900.txt 
rm -f result-901.txt
echo "fi 1 1 74 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-901.txt 
rm -f result-902.txt
echo "fi 1 1 74 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-902.txt 
rm -f result-903.txt
echo "fi 1 1 75 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-903.txt 
rm -f result-904.txt
echo "fi 1 1 75 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-904.txt 
rm -f result-905.txt
echo "fi 1 1 75 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-905.txt 
rm -f result-906.txt
echo "fi 1 1 75 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-906.txt 
rm -f result-907.txt
echo "fi 1 1 75 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-907.txt 
rm -f result-908.txt
echo "fi 1 1 75 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-908.txt 
rm -f result-909.txt
echo "fi 1 1 75 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-909.txt 
rm -f result-910.txt
echo "fi 1 1 76 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-910.txt 
rm -f result-911.txt
echo "fi 1 1 76 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-911.txt 
rm -f result-912.txt
echo "fi 1 1 76 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-912.txt 
rm -f result-913.txt
echo "fi 1 1 76 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-913.txt 
rm -f result-914.txt
echo "fi 1 1 76 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-914.txt 
rm -f result-915.txt
echo "fi 1 1 76 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-915.txt 
rm -f result-916.txt
echo "fi 1 1 76 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-916.txt 
rm -f result-917.txt
echo "fi 1 1 77 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-917.txt 
rm -f result-918.txt
echo "fi 1 1 77 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-918.txt 
rm -f result-919.txt
echo "fi 1 1 77 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-919.txt 
rm -f result-920.txt
echo "fi 1 1 77 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-920.txt 
rm -f result-921.txt
echo "fi 1 1 77 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-921.txt 
rm -f result-922.txt
echo "fi 1 1 77 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-922.txt 
rm -f result-923.txt
echo "fi 1 1 77 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-923.txt 
rm -f result-924.txt
echo "fi 1 1 78 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-924.txt 
rm -f result-925.txt
echo "fi 1 1 78 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-925.txt 
rm -f result-926.txt
echo "fi 1 1 78 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-926.txt 
rm -f result-927.txt
echo "fi 1 1 78 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-927.txt 
rm -f result-928.txt
echo "fi 1 1 78 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-928.txt 
rm -f result-929.txt
echo "fi 1 1 78 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-929.txt 
rm -f result-930.txt
echo "fi 1 1 78 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-930.txt 
rm -f result-931.txt
echo "fi 1 1 79 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-931.txt 
rm -f result-932.txt
echo "fi 1 1 79 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-932.txt 
rm -f result-933.txt
echo "fi 1 1 79 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-933.txt 
rm -f result-934.txt
echo "fi 1 1 79 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-934.txt 
rm -f result-935.txt
echo "fi 1 1 79 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-935.txt 
rm -f result-936.txt
echo "fi 1 1 79 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-936.txt 
rm -f result-937.txt
echo "fi 1 1 79 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-937.txt 
rm -f result-938.txt
echo "fi 1 1 80 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-938.txt 
rm -f result-939.txt
echo "fi 1 1 80 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-939.txt 
rm -f result-940.txt
echo "fi 1 1 80 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-940.txt 
rm -f result-941.txt
echo "fi 1 1 80 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-941.txt 
rm -f result-942.txt
echo "fi 1 1 80 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-942.txt 
rm -f result-943.txt
echo "fi 1 1 80 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-943.txt 
rm -f result-944.txt
echo "fi 1 1 80 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-944.txt 
rm -f result-945.txt
echo "fi 1 1 81 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-945.txt 
rm -f result-946.txt
echo "fi 1 1 81 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-946.txt 
rm -f result-947.txt
echo "fi 1 1 81 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-947.txt 
rm -f result-948.txt
echo "fi 1 1 81 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-948.txt 
rm -f result-949.txt
echo "fi 1 1 81 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-949.txt 
rm -f result-950.txt
echo "fi 1 1 81 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-950.txt 
rm -f result-951.txt
echo "fi 1 1 81 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-951.txt 
rm -f result-952.txt
echo "fi 1 1 82 0 0x80000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-952.txt 
rm -f result-953.txt
echo "fi 1 1 82 0 0x40000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-953.txt 
rm -f result-954.txt
echo "fi 1 1 82 0 0x08000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-954.txt 
rm -f result-955.txt
echo "fi 1 1 82 0 0x00800000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-955.txt 
rm -f result-956.txt
echo "fi 1 1 82 0 0x00400000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-956.txt 
rm -f result-957.txt
echo "fi 1 1 82 0 0x00001000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-957.txt 
rm -f result-958.txt
echo "fi 1 1 82 0 0x00000001 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-958.txt 
rm -f result-959.txt
echo "fi 1 1 83 0 0x80000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-959.txt 
rm -f result-960.txt
echo "fi 1 1 83 0 0x40000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-960.txt 
rm -f result-961.txt
echo "fi 1 1 83 0 0x08000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-961.txt 
rm -f result-962.txt
echo "fi 1 1 83 0 0x00800000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-962.txt 
rm -f result-963.txt
echo "fi 1 1 83 0 0x00400000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-963.txt 
rm -f result-964.txt
echo "fi 1 1 83 0 0x00001000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-964.txt 
rm -f result-965.txt
echo "fi 1 1 83 0 0x00000001 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-965.txt 
rm -f result-966.txt
echo "fi 1 2 7 0 0x80000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-966.txt 
rm -f result-967.txt
echo "fi 1 2 7 0 0x40000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-967.txt 
rm -f result-968.txt
echo "fi 1 2 7 0 0x08000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-968.txt 
rm -f result-969.txt
echo "fi 1 2 7 0 0x00800000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-969.txt 
rm -f result-970.txt
echo "fi 1 2 7 0 0x00400000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-970.txt 
rm -f result-971.txt
echo "fi 1 2 7 0 0x00001000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-971.txt 
rm -f result-972.txt
echo "fi 1 2 7 0 0x00000001 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-972.txt 
rm -f result-973.txt
echo "fi 1 2 8 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-973.txt 
rm -f result-974.txt
echo "fi 1 2 8 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-974.txt 
rm -f result-975.txt
echo "fi 1 2 8 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-975.txt 
rm -f result-976.txt
echo "fi 1 2 8 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-976.txt 
rm -f result-977.txt
echo "fi 1 2 8 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-977.txt 
rm -f result-978.txt
echo "fi 1 2 8 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-978.txt 
rm -f result-979.txt
echo "fi 1 2 8 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-979.txt 
rm -f result-980.txt
echo "fi 1 2 9 0 0x80000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-980.txt 
rm -f result-981.txt
echo "fi 1 2 9 0 0x40000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-981.txt 
rm -f result-982.txt
echo "fi 1 2 9 0 0x08000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-982.txt 
rm -f result-983.txt
echo "fi 1 2 9 0 0x00800000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-983.txt 
rm -f result-984.txt
echo "fi 1 2 9 0 0x00400000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-984.txt 
rm -f result-985.txt
echo "fi 1 2 9 0 0x00001000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-985.txt 
rm -f result-986.txt
echo "fi 1 2 9 0 0x00000001 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-986.txt 
rm -f result-987.txt
echo "fi 1 2 10 0 0x80000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-987.txt 
rm -f result-988.txt
echo "fi 1 2 10 0 0x40000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-988.txt 
rm -f result-989.txt
echo "fi 1 2 10 0 0x08000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-989.txt 
rm -f result-990.txt
echo "fi 1 2 10 0 0x00800000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-990.txt 
rm -f result-991.txt
echo "fi 1 2 10 0 0x00400000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-991.txt 
rm -f result-992.txt
echo "fi 1 2 10 0 0x00001000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-992.txt 
rm -f result-993.txt
echo "fi 1 2 10 0 0x00000001 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-993.txt 
rm -f result-994.txt
echo "fi 1 2 11 0 0x80000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-994.txt 
rm -f result-995.txt
echo "fi 1 2 11 0 0x40000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-995.txt 
rm -f result-996.txt
echo "fi 1 2 11 0 0x08000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-996.txt 
rm -f result-997.txt
echo "fi 1 2 11 0 0x00800000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-997.txt 
rm -f result-998.txt
echo "fi 1 2 11 0 0x00400000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-998.txt 
rm -f result-999.txt
echo "fi 1 2 11 0 0x00001000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-999.txt 
rm -f result-1000.txt
echo "fi 1 2 11 0 0x00000001 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1000.txt 
rm -f result-1001.txt
echo "fi 1 2 12 0 0x80000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1001.txt 
rm -f result-1002.txt
echo "fi 1 2 12 0 0x40000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1002.txt 
rm -f result-1003.txt
echo "fi 1 2 12 0 0x08000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1003.txt 
rm -f result-1004.txt
echo "fi 1 2 12 0 0x00800000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1004.txt 
rm -f result-1005.txt
echo "fi 1 2 12 0 0x00400000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1005.txt 
rm -f result-1006.txt
echo "fi 1 2 12 0 0x00001000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1006.txt 
rm -f result-1007.txt
echo "fi 1 2 12 0 0x00000001 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1007.txt 
rm -f result-1008.txt
echo "fi 1 2 13 0 0x80000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1008.txt 
rm -f result-1009.txt
echo "fi 1 2 13 0 0x40000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1009.txt 
rm -f result-1010.txt
echo "fi 1 2 13 0 0x08000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1010.txt 
rm -f result-1011.txt
echo "fi 1 2 13 0 0x00800000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1011.txt 
rm -f result-1012.txt
echo "fi 1 2 13 0 0x00400000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1012.txt 
rm -f result-1013.txt
echo "fi 1 2 13 0 0x00001000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1013.txt 
rm -f result-1014.txt
echo "fi 1 2 13 0 0x00000001 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1014.txt 
rm -f result-1015.txt
echo "fi 1 2 21 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1015.txt 
rm -f result-1016.txt
echo "fi 1 2 21 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1016.txt 
rm -f result-1017.txt
echo "fi 1 2 21 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1017.txt 
rm -f result-1018.txt
echo "fi 1 2 21 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1018.txt 
rm -f result-1019.txt
echo "fi 1 2 21 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1019.txt 
rm -f result-1020.txt
echo "fi 1 2 21 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1020.txt 
rm -f result-1021.txt
echo "fi 1 2 21 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1021.txt 
rm -f result-1022.txt
echo "fi 1 2 22 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1022.txt 
rm -f result-1023.txt
echo "fi 1 2 22 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1023.txt 
rm -f result-1024.txt
echo "fi 1 2 22 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1024.txt 
rm -f result-1025.txt
echo "fi 1 2 22 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1025.txt 
rm -f result-1026.txt
echo "fi 1 2 22 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1026.txt 
rm -f result-1027.txt
echo "fi 1 2 22 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1027.txt 
rm -f result-1028.txt
echo "fi 1 2 22 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1028.txt 
rm -f result-1029.txt
echo "fi 1 2 23 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1029.txt 
rm -f result-1030.txt
echo "fi 1 2 23 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1030.txt 
rm -f result-1031.txt
echo "fi 1 2 23 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1031.txt 
rm -f result-1032.txt
echo "fi 1 2 23 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1032.txt 
rm -f result-1033.txt
echo "fi 1 2 23 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1033.txt 
rm -f result-1034.txt
echo "fi 1 2 23 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1034.txt 
rm -f result-1035.txt
echo "fi 1 2 23 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1035.txt 
rm -f result-1036.txt
echo "fi 1 2 24 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1036.txt 
rm -f result-1037.txt
echo "fi 1 2 24 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1037.txt 
rm -f result-1038.txt
echo "fi 1 2 24 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1038.txt 
rm -f result-1039.txt
echo "fi 1 2 24 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1039.txt 
rm -f result-1040.txt
echo "fi 1 2 24 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1040.txt 
rm -f result-1041.txt
echo "fi 1 2 24 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1041.txt 
rm -f result-1042.txt
echo "fi 1 2 24 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1042.txt 
rm -f result-1043.txt
echo "fi 1 2 25 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1043.txt 
rm -f result-1044.txt
echo "fi 1 2 25 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1044.txt 
rm -f result-1045.txt
echo "fi 1 2 25 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1045.txt 
rm -f result-1046.txt
echo "fi 1 2 25 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1046.txt 
rm -f result-1047.txt
echo "fi 1 2 25 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1047.txt 
rm -f result-1048.txt
echo "fi 1 2 25 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1048.txt 
rm -f result-1049.txt
echo "fi 1 2 25 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1049.txt 
rm -f result-1050.txt
echo "fi 1 2 26 0 0x80000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1050.txt 
rm -f result-1051.txt
echo "fi 1 2 26 0 0x40000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1051.txt 
rm -f result-1052.txt
echo "fi 1 2 26 0 0x08000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1052.txt 
rm -f result-1053.txt
echo "fi 1 2 26 0 0x00800000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1053.txt 
rm -f result-1054.txt
echo "fi 1 2 26 0 0x00400000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1054.txt 
rm -f result-1055.txt
echo "fi 1 2 26 0 0x00001000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1055.txt 
rm -f result-1056.txt
echo "fi 1 2 26 0 0x00000001 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1056.txt 
rm -f result-1057.txt
echo "fi 1 2 27 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1057.txt 
rm -f result-1058.txt
echo "fi 1 2 27 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1058.txt 
rm -f result-1059.txt
echo "fi 1 2 27 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1059.txt 
rm -f result-1060.txt
echo "fi 1 2 27 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1060.txt 
rm -f result-1061.txt
echo "fi 1 2 27 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1061.txt 
rm -f result-1062.txt
echo "fi 1 2 27 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1062.txt 
rm -f result-1063.txt
echo "fi 1 2 27 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1063.txt 
rm -f result-1064.txt
echo "fi 1 2 28 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1064.txt 
rm -f result-1065.txt
echo "fi 1 2 28 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1065.txt 
rm -f result-1066.txt
echo "fi 1 2 28 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1066.txt 
rm -f result-1067.txt
echo "fi 1 2 28 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1067.txt 
rm -f result-1068.txt
echo "fi 1 2 28 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1068.txt 
rm -f result-1069.txt
echo "fi 1 2 28 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1069.txt 
rm -f result-1070.txt
echo "fi 1 2 28 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1070.txt 
rm -f result-1071.txt
echo "fi 1 2 29 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1071.txt 
rm -f result-1072.txt
echo "fi 1 2 29 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1072.txt 
rm -f result-1073.txt
echo "fi 1 2 29 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1073.txt 
rm -f result-1074.txt
echo "fi 1 2 29 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1074.txt 
rm -f result-1075.txt
echo "fi 1 2 29 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1075.txt 
rm -f result-1076.txt
echo "fi 1 2 29 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1076.txt 
rm -f result-1077.txt
echo "fi 1 2 29 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1077.txt 
rm -f result-1078.txt
echo "fi 1 2 30 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1078.txt 
rm -f result-1079.txt
echo "fi 1 2 30 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1079.txt 
rm -f result-1080.txt
echo "fi 1 2 30 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1080.txt 
rm -f result-1081.txt
echo "fi 1 2 30 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1081.txt 
rm -f result-1082.txt
echo "fi 1 2 30 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1082.txt 
rm -f result-1083.txt
echo "fi 1 2 30 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1083.txt 
rm -f result-1084.txt
echo "fi 1 2 30 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1084.txt 
rm -f result-1085.txt
echo "fi 1 2 31 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1085.txt 
rm -f result-1086.txt
echo "fi 1 2 31 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1086.txt 
rm -f result-1087.txt
echo "fi 1 2 31 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1087.txt 
rm -f result-1088.txt
echo "fi 1 2 31 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1088.txt 
rm -f result-1089.txt
echo "fi 1 2 31 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1089.txt 
rm -f result-1090.txt
echo "fi 1 2 31 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1090.txt 
rm -f result-1091.txt
echo "fi 1 2 31 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1091.txt 
rm -f result-1092.txt
echo "fi 1 2 32 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1092.txt 
rm -f result-1093.txt
echo "fi 1 2 32 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1093.txt 
rm -f result-1094.txt
echo "fi 1 2 32 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1094.txt 
rm -f result-1095.txt
echo "fi 1 2 32 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1095.txt 
rm -f result-1096.txt
echo "fi 1 2 32 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1096.txt 
rm -f result-1097.txt
echo "fi 1 2 32 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1097.txt 
rm -f result-1098.txt
echo "fi 1 2 32 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1098.txt 
rm -f result-1099.txt
echo "fi 1 2 33 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1099.txt 
rm -f result-1100.txt
echo "fi 1 2 33 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1100.txt 
rm -f result-1101.txt
echo "fi 1 2 33 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1101.txt 
rm -f result-1102.txt
echo "fi 1 2 33 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1102.txt 
rm -f result-1103.txt
echo "fi 1 2 33 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1103.txt 
rm -f result-1104.txt
echo "fi 1 2 33 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1104.txt 
rm -f result-1105.txt
echo "fi 1 2 33 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1105.txt 
rm -f result-1106.txt
echo "fi 1 2 34 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1106.txt 
rm -f result-1107.txt
echo "fi 1 2 34 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1107.txt 
rm -f result-1108.txt
echo "fi 1 2 34 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1108.txt 
rm -f result-1109.txt
echo "fi 1 2 34 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1109.txt 
rm -f result-1110.txt
echo "fi 1 2 34 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1110.txt 
rm -f result-1111.txt
echo "fi 1 2 34 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1111.txt 
rm -f result-1112.txt
echo "fi 1 2 34 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1112.txt 
rm -f result-1113.txt
echo "fi 1 2 35 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1113.txt 
rm -f result-1114.txt
echo "fi 1 2 35 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1114.txt 
rm -f result-1115.txt
echo "fi 1 2 35 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1115.txt 
rm -f result-1116.txt
echo "fi 1 2 35 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1116.txt 
rm -f result-1117.txt
echo "fi 1 2 35 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1117.txt 
rm -f result-1118.txt
echo "fi 1 2 35 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1118.txt 
rm -f result-1119.txt
echo "fi 1 2 35 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1119.txt 
rm -f result-1120.txt
echo "fi 1 2 36 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1120.txt 
rm -f result-1121.txt
echo "fi 1 2 36 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1121.txt 
rm -f result-1122.txt
echo "fi 1 2 36 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1122.txt 
rm -f result-1123.txt
echo "fi 1 2 36 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1123.txt 
rm -f result-1124.txt
echo "fi 1 2 36 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1124.txt 
rm -f result-1125.txt
echo "fi 1 2 36 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1125.txt 
rm -f result-1126.txt
echo "fi 1 2 36 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1126.txt 
rm -f result-1127.txt
echo "fi 1 2 45 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1127.txt 
rm -f result-1128.txt
echo "fi 1 2 45 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1128.txt 
rm -f result-1129.txt
echo "fi 1 2 45 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1129.txt 
rm -f result-1130.txt
echo "fi 1 2 45 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1130.txt 
rm -f result-1131.txt
echo "fi 1 2 45 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1131.txt 
rm -f result-1132.txt
echo "fi 1 2 45 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1132.txt 
rm -f result-1133.txt
echo "fi 1 2 45 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1133.txt 
rm -f result-1134.txt
echo "fi 1 2 46 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1134.txt 
rm -f result-1135.txt
echo "fi 1 2 46 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1135.txt 
rm -f result-1136.txt
echo "fi 1 2 46 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1136.txt 
rm -f result-1137.txt
echo "fi 1 2 46 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1137.txt 
rm -f result-1138.txt
echo "fi 1 2 46 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1138.txt 
rm -f result-1139.txt
echo "fi 1 2 46 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1139.txt 
rm -f result-1140.txt
echo "fi 1 2 46 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1140.txt 
rm -f result-1141.txt
echo "fi 1 2 47 127 0x80000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1141.txt 
rm -f result-1142.txt
echo "fi 1 2 47 127 0x40000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1142.txt 
rm -f result-1143.txt
echo "fi 1 2 47 127 0x08000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1143.txt 
rm -f result-1144.txt
echo "fi 1 2 47 127 0x00800000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1144.txt 
rm -f result-1145.txt
echo "fi 1 2 47 127 0x00400000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1145.txt 
rm -f result-1146.txt
echo "fi 1 2 47 127 0x00001000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1146.txt 
rm -f result-1147.txt
echo "fi 1 2 47 127 0x00000001 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1147.txt 
rm -f result-1148.txt
echo "fi 1 2 48 127 0x80000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1148.txt 
rm -f result-1149.txt
echo "fi 1 2 48 127 0x40000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1149.txt 
rm -f result-1150.txt
echo "fi 1 2 48 127 0x08000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1150.txt 
rm -f result-1151.txt
echo "fi 1 2 48 127 0x00800000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1151.txt 
rm -f result-1152.txt
echo "fi 1 2 48 127 0x00400000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1152.txt 
rm -f result-1153.txt
echo "fi 1 2 48 127 0x00001000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1153.txt 
rm -f result-1154.txt
echo "fi 1 2 48 127 0x00000001 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1154.txt 
rm -f result-1155.txt
echo "fi 1 2 49 127 0x80000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1155.txt 
rm -f result-1156.txt
echo "fi 1 2 49 127 0x40000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1156.txt 
rm -f result-1157.txt
echo "fi 1 2 49 127 0x08000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1157.txt 
rm -f result-1158.txt
echo "fi 1 2 49 127 0x00800000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1158.txt 
rm -f result-1159.txt
echo "fi 1 2 49 127 0x00400000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1159.txt 
rm -f result-1160.txt
echo "fi 1 2 49 127 0x00001000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1160.txt 
rm -f result-1161.txt
echo "fi 1 2 49 127 0x00000001 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1161.txt 
rm -f result-1162.txt
echo "fi 1 2 50 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1162.txt 
rm -f result-1163.txt
echo "fi 1 2 50 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1163.txt 
rm -f result-1164.txt
echo "fi 1 2 50 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1164.txt 
rm -f result-1165.txt
echo "fi 1 2 50 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1165.txt 
rm -f result-1166.txt
echo "fi 1 2 50 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1166.txt 
rm -f result-1167.txt
echo "fi 1 2 50 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1167.txt 
rm -f result-1168.txt
echo "fi 1 2 50 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1168.txt 
rm -f result-1169.txt
echo "fi 1 2 51 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1169.txt 
rm -f result-1170.txt
echo "fi 1 2 51 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1170.txt 
rm -f result-1171.txt
echo "fi 1 2 51 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1171.txt 
rm -f result-1172.txt
echo "fi 1 2 51 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1172.txt 
rm -f result-1173.txt
echo "fi 1 2 51 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1173.txt 
rm -f result-1174.txt
echo "fi 1 2 51 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1174.txt 
rm -f result-1175.txt
echo "fi 1 2 51 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1175.txt 
rm -f result-1176.txt
echo "fi 1 2 52 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1176.txt 
rm -f result-1177.txt
echo "fi 1 2 52 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1177.txt 
rm -f result-1178.txt
echo "fi 1 2 52 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1178.txt 
rm -f result-1179.txt
echo "fi 1 2 52 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1179.txt 
rm -f result-1180.txt
echo "fi 1 2 52 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1180.txt 
rm -f result-1181.txt
echo "fi 1 2 52 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1181.txt 
rm -f result-1182.txt
echo "fi 1 2 52 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1182.txt 
rm -f result-1183.txt
echo "fi 1 2 53 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1183.txt 
rm -f result-1184.txt
echo "fi 1 2 53 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1184.txt 
rm -f result-1185.txt
echo "fi 1 2 53 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1185.txt 
rm -f result-1186.txt
echo "fi 1 2 53 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1186.txt 
rm -f result-1187.txt
echo "fi 1 2 53 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1187.txt 
rm -f result-1188.txt
echo "fi 1 2 53 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1188.txt 
rm -f result-1189.txt
echo "fi 1 2 53 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1189.txt 
rm -f result-1190.txt
echo "fi 1 2 54 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1190.txt 
rm -f result-1191.txt
echo "fi 1 2 54 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1191.txt 
rm -f result-1192.txt
echo "fi 1 2 54 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1192.txt 
rm -f result-1193.txt
echo "fi 1 2 54 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1193.txt 
rm -f result-1194.txt
echo "fi 1 2 54 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1194.txt 
rm -f result-1195.txt
echo "fi 1 2 54 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1195.txt 
rm -f result-1196.txt
echo "fi 1 2 54 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1196.txt 
rm -f result-1197.txt
echo "fi 1 2 55 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1197.txt 
rm -f result-1198.txt
echo "fi 1 2 55 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1198.txt 
rm -f result-1199.txt
echo "fi 1 2 55 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1199.txt 
rm -f result-1200.txt
echo "fi 1 2 55 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1200.txt 
rm -f result-1201.txt
echo "fi 1 2 55 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1201.txt 
rm -f result-1202.txt
echo "fi 1 2 55 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1202.txt 
rm -f result-1203.txt
echo "fi 1 2 55 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1203.txt 
rm -f result-1204.txt
echo "fi 1 2 56 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1204.txt 
rm -f result-1205.txt
echo "fi 1 2 56 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1205.txt 
rm -f result-1206.txt
echo "fi 1 2 56 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1206.txt 
rm -f result-1207.txt
echo "fi 1 2 56 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1207.txt 
rm -f result-1208.txt
echo "fi 1 2 56 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1208.txt 
rm -f result-1209.txt
echo "fi 1 2 56 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1209.txt 
rm -f result-1210.txt
echo "fi 1 2 56 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1210.txt 
rm -f result-1211.txt
echo "fi 1 2 57 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1211.txt 
rm -f result-1212.txt
echo "fi 1 2 57 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1212.txt 
rm -f result-1213.txt
echo "fi 1 2 57 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1213.txt 
rm -f result-1214.txt
echo "fi 1 2 57 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1214.txt 
rm -f result-1215.txt
echo "fi 1 2 57 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1215.txt 
rm -f result-1216.txt
echo "fi 1 2 57 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1216.txt 
rm -f result-1217.txt
echo "fi 1 2 57 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1217.txt 
rm -f result-1218.txt
echo "fi 1 2 58 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1218.txt 
rm -f result-1219.txt
echo "fi 1 2 58 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1219.txt 
rm -f result-1220.txt
echo "fi 1 2 58 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1220.txt 
rm -f result-1221.txt
echo "fi 1 2 58 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1221.txt 
rm -f result-1222.txt
echo "fi 1 2 58 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1222.txt 
rm -f result-1223.txt
echo "fi 1 2 58 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1223.txt 
rm -f result-1224.txt
echo "fi 1 2 58 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1224.txt 
rm -f result-1225.txt
echo "fi 1 2 59 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1225.txt 
rm -f result-1226.txt
echo "fi 1 2 59 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1226.txt 
rm -f result-1227.txt
echo "fi 1 2 59 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1227.txt 
rm -f result-1228.txt
echo "fi 1 2 59 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1228.txt 
rm -f result-1229.txt
echo "fi 1 2 59 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1229.txt 
rm -f result-1230.txt
echo "fi 1 2 59 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1230.txt 
rm -f result-1231.txt
echo "fi 1 2 59 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1231.txt 
rm -f result-1232.txt
echo "fi 1 2 60 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1232.txt 
rm -f result-1233.txt
echo "fi 1 2 60 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1233.txt 
rm -f result-1234.txt
echo "fi 1 2 60 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1234.txt 
rm -f result-1235.txt
echo "fi 1 2 60 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1235.txt 
rm -f result-1236.txt
echo "fi 1 2 60 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1236.txt 
rm -f result-1237.txt
echo "fi 1 2 60 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1237.txt 
rm -f result-1238.txt
echo "fi 1 2 60 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1238.txt 
rm -f result-1239.txt
echo "fi 1 2 61 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1239.txt 
rm -f result-1240.txt
echo "fi 1 2 61 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1240.txt 
rm -f result-1241.txt
echo "fi 1 2 61 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1241.txt 
rm -f result-1242.txt
echo "fi 1 2 61 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1242.txt 
rm -f result-1243.txt
echo "fi 1 2 61 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1243.txt 
rm -f result-1244.txt
echo "fi 1 2 61 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1244.txt 
rm -f result-1245.txt
echo "fi 1 2 61 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1245.txt 
rm -f result-1246.txt
echo "fi 1 2 62 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1246.txt 
rm -f result-1247.txt
echo "fi 1 2 62 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1247.txt 
rm -f result-1248.txt
echo "fi 1 2 62 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1248.txt 
rm -f result-1249.txt
echo "fi 1 2 62 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1249.txt 
rm -f result-1250.txt
echo "fi 1 2 62 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1250.txt 
rm -f result-1251.txt
echo "fi 1 2 62 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1251.txt 
rm -f result-1252.txt
echo "fi 1 2 62 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1252.txt 
rm -f result-1253.txt
echo "fi 1 2 63 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1253.txt 
rm -f result-1254.txt
echo "fi 1 2 63 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1254.txt 
rm -f result-1255.txt
echo "fi 1 2 63 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1255.txt 
rm -f result-1256.txt
echo "fi 1 2 63 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1256.txt 
rm -f result-1257.txt
echo "fi 1 2 63 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1257.txt 
rm -f result-1258.txt
echo "fi 1 2 63 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1258.txt 
rm -f result-1259.txt
echo "fi 1 2 63 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1259.txt 
rm -f result-1260.txt
echo "fi 1 2 64 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1260.txt 
rm -f result-1261.txt
echo "fi 1 2 64 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1261.txt 
rm -f result-1262.txt
echo "fi 1 2 64 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1262.txt 
rm -f result-1263.txt
echo "fi 1 2 64 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1263.txt 
rm -f result-1264.txt
echo "fi 1 2 64 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1264.txt 
rm -f result-1265.txt
echo "fi 1 2 64 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1265.txt 
rm -f result-1266.txt
echo "fi 1 2 64 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1266.txt 
rm -f result-1267.txt
echo "fi 1 2 65 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1267.txt 
rm -f result-1268.txt
echo "fi 1 2 65 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1268.txt 
rm -f result-1269.txt
echo "fi 1 2 65 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1269.txt 
rm -f result-1270.txt
echo "fi 1 2 65 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1270.txt 
rm -f result-1271.txt
echo "fi 1 2 65 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1271.txt 
rm -f result-1272.txt
echo "fi 1 2 65 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1272.txt 
rm -f result-1273.txt
echo "fi 1 2 65 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1273.txt 
rm -f result-1274.txt
echo "fi 1 2 66 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1274.txt 
rm -f result-1275.txt
echo "fi 1 2 66 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1275.txt 
rm -f result-1276.txt
echo "fi 1 2 66 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1276.txt 
rm -f result-1277.txt
echo "fi 1 2 66 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1277.txt 
rm -f result-1278.txt
echo "fi 1 2 66 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1278.txt 
rm -f result-1279.txt
echo "fi 1 2 66 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1279.txt 
rm -f result-1280.txt
echo "fi 1 2 66 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1280.txt 
rm -f result-1281.txt
echo "fi 1 2 67 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1281.txt 
rm -f result-1282.txt
echo "fi 1 2 67 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1282.txt 
rm -f result-1283.txt
echo "fi 1 2 67 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1283.txt 
rm -f result-1284.txt
echo "fi 1 2 67 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1284.txt 
rm -f result-1285.txt
echo "fi 1 2 67 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1285.txt 
rm -f result-1286.txt
echo "fi 1 2 67 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1286.txt 
rm -f result-1287.txt
echo "fi 1 2 67 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1287.txt 
rm -f result-1288.txt
echo "fi 1 2 68 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1288.txt 
rm -f result-1289.txt
echo "fi 1 2 68 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1289.txt 
rm -f result-1290.txt
echo "fi 1 2 68 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1290.txt 
rm -f result-1291.txt
echo "fi 1 2 68 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1291.txt 
rm -f result-1292.txt
echo "fi 1 2 68 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1292.txt 
rm -f result-1293.txt
echo "fi 1 2 68 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1293.txt 
rm -f result-1294.txt
echo "fi 1 2 68 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1294.txt 
rm -f result-1295.txt
echo "fi 1 2 69 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1295.txt 
rm -f result-1296.txt
echo "fi 1 2 69 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1296.txt 
rm -f result-1297.txt
echo "fi 1 2 69 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1297.txt 
rm -f result-1298.txt
echo "fi 1 2 69 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1298.txt 
rm -f result-1299.txt
echo "fi 1 2 69 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1299.txt 
rm -f result-1300.txt
echo "fi 1 2 69 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1300.txt 
rm -f result-1301.txt
echo "fi 1 2 69 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1301.txt 
rm -f result-1302.txt
echo "fi 1 2 70 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1302.txt 
rm -f result-1303.txt
echo "fi 1 2 70 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1303.txt 
rm -f result-1304.txt
echo "fi 1 2 70 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1304.txt 
rm -f result-1305.txt
echo "fi 1 2 70 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1305.txt 
rm -f result-1306.txt
echo "fi 1 2 70 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1306.txt 
rm -f result-1307.txt
echo "fi 1 2 70 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1307.txt 
rm -f result-1308.txt
echo "fi 1 2 70 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1308.txt 
rm -f result-1309.txt
echo "fi 1 2 71 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1309.txt 
rm -f result-1310.txt
echo "fi 1 2 71 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1310.txt 
rm -f result-1311.txt
echo "fi 1 2 71 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1311.txt 
rm -f result-1312.txt
echo "fi 1 2 71 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1312.txt 
rm -f result-1313.txt
echo "fi 1 2 71 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1313.txt 
rm -f result-1314.txt
echo "fi 1 2 71 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1314.txt 
rm -f result-1315.txt
echo "fi 1 2 71 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1315.txt 
rm -f result-1316.txt
echo "fi 1 2 72 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1316.txt 
rm -f result-1317.txt
echo "fi 1 2 72 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1317.txt 
rm -f result-1318.txt
echo "fi 1 2 72 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1318.txt 
rm -f result-1319.txt
echo "fi 1 2 72 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1319.txt 
rm -f result-1320.txt
echo "fi 1 2 72 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1320.txt 
rm -f result-1321.txt
echo "fi 1 2 72 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1321.txt 
rm -f result-1322.txt
echo "fi 1 2 72 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1322.txt 
rm -f result-1323.txt
echo "fi 1 2 73 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1323.txt 
rm -f result-1324.txt
echo "fi 1 2 73 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1324.txt 
rm -f result-1325.txt
echo "fi 1 2 73 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1325.txt 
rm -f result-1326.txt
echo "fi 1 2 73 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1326.txt 
rm -f result-1327.txt
echo "fi 1 2 73 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1327.txt 
rm -f result-1328.txt
echo "fi 1 2 73 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1328.txt 
rm -f result-1329.txt
echo "fi 1 2 73 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1329.txt 
rm -f result-1330.txt
echo "fi 1 2 74 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1330.txt 
rm -f result-1331.txt
echo "fi 1 2 74 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1331.txt 
rm -f result-1332.txt
echo "fi 1 2 74 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1332.txt 
rm -f result-1333.txt
echo "fi 1 2 74 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1333.txt 
rm -f result-1334.txt
echo "fi 1 2 74 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1334.txt 
rm -f result-1335.txt
echo "fi 1 2 74 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1335.txt 
rm -f result-1336.txt
echo "fi 1 2 74 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1336.txt 
rm -f result-1337.txt
echo "fi 1 2 75 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1337.txt 
rm -f result-1338.txt
echo "fi 1 2 75 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1338.txt 
rm -f result-1339.txt
echo "fi 1 2 75 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1339.txt 
rm -f result-1340.txt
echo "fi 1 2 75 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1340.txt 
rm -f result-1341.txt
echo "fi 1 2 75 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1341.txt 
rm -f result-1342.txt
echo "fi 1 2 75 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1342.txt 
rm -f result-1343.txt
echo "fi 1 2 75 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1343.txt 
rm -f result-1344.txt
echo "fi 1 2 76 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1344.txt 
rm -f result-1345.txt
echo "fi 1 2 76 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1345.txt 
rm -f result-1346.txt
echo "fi 1 2 76 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1346.txt 
rm -f result-1347.txt
echo "fi 1 2 76 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1347.txt 
rm -f result-1348.txt
echo "fi 1 2 76 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1348.txt 
rm -f result-1349.txt
echo "fi 1 2 76 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1349.txt 
rm -f result-1350.txt
echo "fi 1 2 76 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1350.txt 
rm -f result-1351.txt
echo "fi 1 2 77 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1351.txt 
rm -f result-1352.txt
echo "fi 1 2 77 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1352.txt 
rm -f result-1353.txt
echo "fi 1 2 77 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1353.txt 
rm -f result-1354.txt
echo "fi 1 2 77 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1354.txt 
rm -f result-1355.txt
echo "fi 1 2 77 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1355.txt 
rm -f result-1356.txt
echo "fi 1 2 77 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1356.txt 
rm -f result-1357.txt
echo "fi 1 2 77 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1357.txt 
rm -f result-1358.txt
echo "fi 1 2 78 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1358.txt 
rm -f result-1359.txt
echo "fi 1 2 78 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1359.txt 
rm -f result-1360.txt
echo "fi 1 2 78 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1360.txt 
rm -f result-1361.txt
echo "fi 1 2 78 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1361.txt 
rm -f result-1362.txt
echo "fi 1 2 78 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1362.txt 
rm -f result-1363.txt
echo "fi 1 2 78 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1363.txt 
rm -f result-1364.txt
echo "fi 1 2 78 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1364.txt 
rm -f result-1365.txt
echo "fi 1 2 79 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1365.txt 
rm -f result-1366.txt
echo "fi 1 2 79 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1366.txt 
rm -f result-1367.txt
echo "fi 1 2 79 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1367.txt 
rm -f result-1368.txt
echo "fi 1 2 79 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1368.txt 
rm -f result-1369.txt
echo "fi 1 2 79 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1369.txt 
rm -f result-1370.txt
echo "fi 1 2 79 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1370.txt 
rm -f result-1371.txt
echo "fi 1 2 79 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1371.txt 
rm -f result-1372.txt
echo "fi 1 2 80 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1372.txt 
rm -f result-1373.txt
echo "fi 1 2 80 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1373.txt 
rm -f result-1374.txt
echo "fi 1 2 80 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1374.txt 
rm -f result-1375.txt
echo "fi 1 2 80 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1375.txt 
rm -f result-1376.txt
echo "fi 1 2 80 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1376.txt 
rm -f result-1377.txt
echo "fi 1 2 80 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1377.txt 
rm -f result-1378.txt
echo "fi 1 2 80 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1378.txt 
rm -f result-1379.txt
echo "fi 1 2 81 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1379.txt 
rm -f result-1380.txt
echo "fi 1 2 81 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1380.txt 
rm -f result-1381.txt
echo "fi 1 2 81 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1381.txt 
rm -f result-1382.txt
echo "fi 1 2 81 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1382.txt 
rm -f result-1383.txt
echo "fi 1 2 81 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1383.txt 
rm -f result-1384.txt
echo "fi 1 2 81 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1384.txt 
rm -f result-1385.txt
echo "fi 1 2 81 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1385.txt 
rm -f result-1386.txt
echo "fi 1 2 82 0 0x80000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1386.txt 
rm -f result-1387.txt
echo "fi 1 2 82 0 0x40000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1387.txt 
rm -f result-1388.txt
echo "fi 1 2 82 0 0x08000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1388.txt 
rm -f result-1389.txt
echo "fi 1 2 82 0 0x00800000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1389.txt 
rm -f result-1390.txt
echo "fi 1 2 82 0 0x00400000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1390.txt 
rm -f result-1391.txt
echo "fi 1 2 82 0 0x00001000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1391.txt 
rm -f result-1392.txt
echo "fi 1 2 82 0 0x00000001 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1392.txt 
rm -f result-1393.txt
echo "fi 1 2 83 0 0x80000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1393.txt 
rm -f result-1394.txt
echo "fi 1 2 83 0 0x40000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1394.txt 
rm -f result-1395.txt
echo "fi 1 2 83 0 0x08000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1395.txt 
rm -f result-1396.txt
echo "fi 1 2 83 0 0x00800000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1396.txt 
rm -f result-1397.txt
echo "fi 1 2 83 0 0x00400000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1397.txt 
rm -f result-1398.txt
echo "fi 1 2 83 0 0x00001000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1398.txt 
rm -f result-1399.txt
echo "fi 1 2 83 0 0x00000001 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1399.txt 
rm -f result-1400.txt
echo "fi 1 3 7 0 0x80000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1400.txt 
rm -f result-1401.txt
echo "fi 1 3 7 0 0x40000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1401.txt 
rm -f result-1402.txt
echo "fi 1 3 7 0 0x08000000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1402.txt 
rm -f result-1403.txt
echo "fi 1 3 7 0 0x00800000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1403.txt 
rm -f result-1404.txt
echo "fi 1 3 7 0 0x00400000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1404.txt 
rm -f result-1405.txt
echo "fi 1 3 7 0 0x00001000 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1405.txt 
rm -f result-1406.txt
echo "fi 1 3 7 0 0x00000001 int numK" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1406.txt 
rm -f result-1407.txt
echo "fi 1 3 8 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1407.txt 
rm -f result-1408.txt
echo "fi 1 3 8 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1408.txt 
rm -f result-1409.txt
echo "fi 1 3 8 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1409.txt 
rm -f result-1410.txt
echo "fi 1 3 8 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1410.txt 
rm -f result-1411.txt
echo "fi 1 3 8 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1411.txt 
rm -f result-1412.txt
echo "fi 1 3 8 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1412.txt 
rm -f result-1413.txt
echo "fi 1 3 8 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1413.txt 
rm -f result-1414.txt
echo "fi 1 3 9 0 0x80000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1414.txt 
rm -f result-1415.txt
echo "fi 1 3 9 0 0x40000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1415.txt 
rm -f result-1416.txt
echo "fi 1 3 9 0 0x08000000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1416.txt 
rm -f result-1417.txt
echo "fi 1 3 9 0 0x00800000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1417.txt 
rm -f result-1418.txt
echo "fi 1 3 9 0 0x00400000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1418.txt 
rm -f result-1419.txt
echo "fi 1 3 9 0 0x00001000 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1419.txt 
rm -f result-1420.txt
echo "fi 1 3 9 0 0x00000001 fp_pt x" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1420.txt 
rm -f result-1421.txt
echo "fi 1 3 10 0 0x80000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1421.txt 
rm -f result-1422.txt
echo "fi 1 3 10 0 0x40000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1422.txt 
rm -f result-1423.txt
echo "fi 1 3 10 0 0x08000000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1423.txt 
rm -f result-1424.txt
echo "fi 1 3 10 0 0x00800000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1424.txt 
rm -f result-1425.txt
echo "fi 1 3 10 0 0x00400000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1425.txt 
rm -f result-1426.txt
echo "fi 1 3 10 0 0x00001000 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1426.txt 
rm -f result-1427.txt
echo "fi 1 3 10 0 0x00000001 fp_pt y" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1427.txt 
rm -f result-1428.txt
echo "fi 1 3 11 0 0x80000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1428.txt 
rm -f result-1429.txt
echo "fi 1 3 11 0 0x40000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1429.txt 
rm -f result-1430.txt
echo "fi 1 3 11 0 0x08000000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1430.txt 
rm -f result-1431.txt
echo "fi 1 3 11 0 0x00800000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1431.txt 
rm -f result-1432.txt
echo "fi 1 3 11 0 0x00400000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1432.txt 
rm -f result-1433.txt
echo "fi 1 3 11 0 0x00001000 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1433.txt 
rm -f result-1434.txt
echo "fi 1 3 11 0 0x00000001 fp_pt z" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1434.txt 
rm -f result-1435.txt
echo "fi 1 3 12 0 0x80000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1435.txt 
rm -f result-1436.txt
echo "fi 1 3 12 0 0x40000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1436.txt 
rm -f result-1437.txt
echo "fi 1 3 12 0 0x08000000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1437.txt 
rm -f result-1438.txt
echo "fi 1 3 12 0 0x00800000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1438.txt 
rm -f result-1439.txt
echo "fi 1 3 12 0 0x00400000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1439.txt 
rm -f result-1440.txt
echo "fi 1 3 12 0 0x00001000 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1440.txt 
rm -f result-1441.txt
echo "fi 1 3 12 0 0x00000001 fp_pt outR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1441.txt 
rm -f result-1442.txt
echo "fi 1 3 13 0 0x80000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1442.txt 
rm -f result-1443.txt
echo "fi 1 3 13 0 0x40000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1443.txt 
rm -f result-1444.txt
echo "fi 1 3 13 0 0x08000000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1444.txt 
rm -f result-1445.txt
echo "fi 1 3 13 0 0x00800000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1445.txt 
rm -f result-1446.txt
echo "fi 1 3 13 0 0x00400000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1446.txt 
rm -f result-1447.txt
echo "fi 1 3 13 0 0x00001000 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1447.txt 
rm -f result-1448.txt
echo "fi 1 3 13 0 0x00000001 fp_pt outI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1448.txt 
rm -f result-1449.txt
echo "fi 1 3 21 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1449.txt 
rm -f result-1450.txt
echo "fi 1 3 21 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1450.txt 
rm -f result-1451.txt
echo "fi 1 3 21 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1451.txt 
rm -f result-1452.txt
echo "fi 1 3 21 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1452.txt 
rm -f result-1453.txt
echo "fi 1 3 21 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1453.txt 
rm -f result-1454.txt
echo "fi 1 3 21 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1454.txt 
rm -f result-1455.txt
echo "fi 1 3 21 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1455.txt 
rm -f result-1456.txt
echo "fi 1 3 22 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1456.txt 
rm -f result-1457.txt
echo "fi 1 3 22 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1457.txt 
rm -f result-1458.txt
echo "fi 1 3 22 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1458.txt 
rm -f result-1459.txt
echo "fi 1 3 22 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1459.txt 
rm -f result-1460.txt
echo "fi 1 3 22 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1460.txt 
rm -f result-1461.txt
echo "fi 1 3 22 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1461.txt 
rm -f result-1462.txt
echo "fi 1 3 22 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1462.txt 
rm -f result-1463.txt
echo "fi 1 3 23 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1463.txt 
rm -f result-1464.txt
echo "fi 1 3 23 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1464.txt 
rm -f result-1465.txt
echo "fi 1 3 23 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1465.txt 
rm -f result-1466.txt
echo "fi 1 3 23 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1466.txt 
rm -f result-1467.txt
echo "fi 1 3 23 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1467.txt 
rm -f result-1468.txt
echo "fi 1 3 23 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1468.txt 
rm -f result-1469.txt
echo "fi 1 3 23 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1469.txt 
rm -f result-1470.txt
echo "fi 1 3 24 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1470.txt 
rm -f result-1471.txt
echo "fi 1 3 24 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1471.txt 
rm -f result-1472.txt
echo "fi 1 3 24 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1472.txt 
rm -f result-1473.txt
echo "fi 1 3 24 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1473.txt 
rm -f result-1474.txt
echo "fi 1 3 24 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1474.txt 
rm -f result-1475.txt
echo "fi 1 3 24 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1475.txt 
rm -f result-1476.txt
echo "fi 1 3 24 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1476.txt 
rm -f result-1477.txt
echo "fi 1 3 25 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1477.txt 
rm -f result-1478.txt
echo "fi 1 3 25 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1478.txt 
rm -f result-1479.txt
echo "fi 1 3 25 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1479.txt 
rm -f result-1480.txt
echo "fi 1 3 25 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1480.txt 
rm -f result-1481.txt
echo "fi 1 3 25 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1481.txt 
rm -f result-1482.txt
echo "fi 1 3 25 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1482.txt 
rm -f result-1483.txt
echo "fi 1 3 25 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1483.txt 
rm -f result-1484.txt
echo "fi 1 3 26 0 0x80000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1484.txt 
rm -f result-1485.txt
echo "fi 1 3 26 0 0x40000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1485.txt 
rm -f result-1486.txt
echo "fi 1 3 26 0 0x08000000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1486.txt 
rm -f result-1487.txt
echo "fi 1 3 26 0 0x00800000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1487.txt 
rm -f result-1488.txt
echo "fi 1 3 26 0 0x00400000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1488.txt 
rm -f result-1489.txt
echo "fi 1 3 26 0 0x00001000 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1489.txt 
rm -f result-1490.txt
echo "fi 1 3 26 0 0x00000001 int xIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1490.txt 
rm -f result-1491.txt
echo "fi 1 3 27 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1491.txt 
rm -f result-1492.txt
echo "fi 1 3 27 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1492.txt 
rm -f result-1493.txt
echo "fi 1 3 27 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1493.txt 
rm -f result-1494.txt
echo "fi 1 3 27 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1494.txt 
rm -f result-1495.txt
echo "fi 1 3 27 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1495.txt 
rm -f result-1496.txt
echo "fi 1 3 27 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1496.txt 
rm -f result-1497.txt
echo "fi 1 3 27 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1497.txt 
rm -f result-1498.txt
echo "fi 1 3 28 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1498.txt 
rm -f result-1499.txt
echo "fi 1 3 28 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1499.txt 
rm -f result-1500.txt
echo "fi 1 3 28 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1500.txt 
rm -f result-1501.txt
echo "fi 1 3 28 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1501.txt 
rm -f result-1502.txt
echo "fi 1 3 28 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1502.txt 
rm -f result-1503.txt
echo "fi 1 3 28 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1503.txt 
rm -f result-1504.txt
echo "fi 1 3 28 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1504.txt 
rm -f result-1505.txt
echo "fi 1 3 29 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1505.txt 
rm -f result-1506.txt
echo "fi 1 3 29 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1506.txt 
rm -f result-1507.txt
echo "fi 1 3 29 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1507.txt 
rm -f result-1508.txt
echo "fi 1 3 29 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1508.txt 
rm -f result-1509.txt
echo "fi 1 3 29 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1509.txt 
rm -f result-1510.txt
echo "fi 1 3 29 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1510.txt 
rm -f result-1511.txt
echo "fi 1 3 29 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1511.txt 
rm -f result-1512.txt
echo "fi 1 3 30 0 0x80000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1512.txt 
rm -f result-1513.txt
echo "fi 1 3 30 0 0x40000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1513.txt 
rm -f result-1514.txt
echo "fi 1 3 30 0 0x08000000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1514.txt 
rm -f result-1515.txt
echo "fi 1 3 30 0 0x00800000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1515.txt 
rm -f result-1516.txt
echo "fi 1 3 30 0 0x00400000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1516.txt 
rm -f result-1517.txt
echo "fi 1 3 30 0 0x00001000 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1517.txt 
rm -f result-1518.txt
echo "fi 1 3 30 0 0x00000001 fp_pt test" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1518.txt 
rm -f result-1519.txt
echo "fi 1 3 31 0 0x80000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1519.txt 
rm -f result-1520.txt
echo "fi 1 3 31 0 0x40000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1520.txt 
rm -f result-1521.txt
echo "fi 1 3 31 0 0x08000000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1521.txt 
rm -f result-1522.txt
echo "fi 1 3 31 0 0x00800000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1522.txt 
rm -f result-1523.txt
echo "fi 1 3 31 0 0x00400000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1523.txt 
rm -f result-1524.txt
echo "fi 1 3 31 0 0x00001000 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1524.txt 
rm -f result-1525.txt
echo "fi 1 3 31 0 0x00000001 fp sX" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1525.txt 
rm -f result-1526.txt
echo "fi 1 3 32 0 0x80000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1526.txt 
rm -f result-1527.txt
echo "fi 1 3 32 0 0x40000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1527.txt 
rm -f result-1528.txt
echo "fi 1 3 32 0 0x08000000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1528.txt 
rm -f result-1529.txt
echo "fi 1 3 32 0 0x00800000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1529.txt 
rm -f result-1530.txt
echo "fi 1 3 32 0 0x00400000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1530.txt 
rm -f result-1531.txt
echo "fi 1 3 32 0 0x00001000 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1531.txt 
rm -f result-1532.txt
echo "fi 1 3 32 0 0x00000001 fp sY" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1532.txt 
rm -f result-1533.txt
echo "fi 1 3 33 0 0x80000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1533.txt 
rm -f result-1534.txt
echo "fi 1 3 33 0 0x40000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1534.txt 
rm -f result-1535.txt
echo "fi 1 3 33 0 0x08000000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1535.txt 
rm -f result-1536.txt
echo "fi 1 3 33 0 0x00800000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1536.txt 
rm -f result-1537.txt
echo "fi 1 3 33 0 0x00400000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1537.txt 
rm -f result-1538.txt
echo "fi 1 3 33 0 0x00001000 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1538.txt 
rm -f result-1539.txt
echo "fi 1 3 33 0 0x00000001 fp sZ" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1539.txt 
rm -f result-1540.txt
echo "fi 1 3 34 0 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1540.txt 
rm -f result-1541.txt
echo "fi 1 3 34 0 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1541.txt 
rm -f result-1542.txt
echo "fi 1 3 34 0 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1542.txt 
rm -f result-1543.txt
echo "fi 1 3 34 0 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1543.txt 
rm -f result-1544.txt
echo "fi 1 3 34 0 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1544.txt 
rm -f result-1545.txt
echo "fi 1 3 34 0 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1545.txt 
rm -f result-1546.txt
echo "fi 1 3 34 0 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1546.txt 
rm -f result-1547.txt
echo "fi 1 3 35 0 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1547.txt 
rm -f result-1548.txt
echo "fi 1 3 35 0 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1548.txt 
rm -f result-1549.txt
echo "fi 1 3 35 0 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1549.txt 
rm -f result-1550.txt
echo "fi 1 3 35 0 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1550.txt 
rm -f result-1551.txt
echo "fi 1 3 35 0 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1551.txt 
rm -f result-1552.txt
echo "fi 1 3 35 0 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1552.txt 
rm -f result-1553.txt
echo "fi 1 3 35 0 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1553.txt 
rm -f result-1554.txt
echo "fi 1 3 36 0 0x80000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1554.txt 
rm -f result-1555.txt
echo "fi 1 3 36 0 0x40000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1555.txt 
rm -f result-1556.txt
echo "fi 1 3 36 0 0x08000000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1556.txt 
rm -f result-1557.txt
echo "fi 1 3 36 0 0x00800000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1557.txt 
rm -f result-1558.txt
echo "fi 1 3 36 0 0x00400000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1558.txt 
rm -f result-1559.txt
echo "fi 1 3 36 0 0x00001000 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1559.txt 
rm -f result-1560.txt
echo "fi 1 3 36 0 0x00000001 int kCnt" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1560.txt 
rm -f result-1561.txt
echo "fi 1 3 45 0 0x80000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1561.txt 
rm -f result-1562.txt
echo "fi 1 3 45 0 0x40000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1562.txt 
rm -f result-1563.txt
echo "fi 1 3 45 0 0x08000000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1563.txt 
rm -f result-1564.txt
echo "fi 1 3 45 0 0x00800000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1564.txt 
rm -f result-1565.txt
echo "fi 1 3 45 0 0x00400000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1565.txt 
rm -f result-1566.txt
echo "fi 1 3 45 0 0x00001000 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1566.txt 
rm -f result-1567.txt
echo "fi 1 3 45 0 0x00000001 int kIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1567.txt 
rm -f result-1568.txt
echo "fi 1 3 46 0 0x80000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1568.txt 
rm -f result-1569.txt
echo "fi 1 3 46 0 0x40000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1569.txt 
rm -f result-1570.txt
echo "fi 1 3 46 0 0x08000000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1570.txt 
rm -f result-1571.txt
echo "fi 1 3 46 0 0x00800000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1571.txt 
rm -f result-1572.txt
echo "fi 1 3 46 0 0x00400000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1572.txt 
rm -f result-1573.txt
echo "fi 1 3 46 0 0x00001000 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1573.txt 
rm -f result-1574.txt
echo "fi 1 3 46 0 0x00000001 int kGlobalIndex" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1574.txt 
rm -f result-1575.txt
echo "fi 1 3 47 127 0x80000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1575.txt 
rm -f result-1576.txt
echo "fi 1 3 47 127 0x40000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1576.txt 
rm -f result-1577.txt
echo "fi 1 3 47 127 0x08000000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1577.txt 
rm -f result-1578.txt
echo "fi 1 3 47 127 0x00800000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1578.txt 
rm -f result-1579.txt
echo "fi 1 3 47 127 0x00400000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1579.txt 
rm -f result-1580.txt
echo "fi 1 3 47 127 0x00001000 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1580.txt 
rm -f result-1581.txt
echo "fi 1 3 47 127 0x00000001 fp expArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1581.txt 
rm -f result-1582.txt
echo "fi 1 3 48 127 0x80000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1582.txt 
rm -f result-1583.txt
echo "fi 1 3 48 127 0x40000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1583.txt 
rm -f result-1584.txt
echo "fi 1 3 48 127 0x08000000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1584.txt 
rm -f result-1585.txt
echo "fi 1 3 48 127 0x00800000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1585.txt 
rm -f result-1586.txt
echo "fi 1 3 48 127 0x00400000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1586.txt 
rm -f result-1587.txt
echo "fi 1 3 48 127 0x00001000 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1587.txt 
rm -f result-1588.txt
echo "fi 1 3 48 127 0x00000001 fp cosArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1588.txt 
rm -f result-1589.txt
echo "fi 1 3 49 127 0x80000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1589.txt 
rm -f result-1590.txt
echo "fi 1 3 49 127 0x40000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1590.txt 
rm -f result-1591.txt
echo "fi 1 3 49 127 0x08000000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1591.txt 
rm -f result-1592.txt
echo "fi 1 3 49 127 0x00800000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1592.txt 
rm -f result-1593.txt
echo "fi 1 3 49 127 0x00400000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1593.txt 
rm -f result-1594.txt
echo "fi 1 3 49 127 0x00001000 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1594.txt 
rm -f result-1595.txt
echo "fi 1 3 49 127 0x00000001 fp sinArg" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1595.txt 
rm -f result-1596.txt
echo "fi 1 3 50 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1596.txt 
rm -f result-1597.txt
echo "fi 1 3 50 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1597.txt 
rm -f result-1598.txt
echo "fi 1 3 50 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1598.txt 
rm -f result-1599.txt
echo "fi 1 3 50 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1599.txt 
rm -f result-1600.txt
echo "fi 1 3 50 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1600.txt 
rm -f result-1601.txt
echo "fi 1 3 50 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1601.txt 
rm -f result-1602.txt
echo "fi 1 3 50 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1602.txt 
rm -f result-1603.txt
echo "fi 1 3 51 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1603.txt 
rm -f result-1604.txt
echo "fi 1 3 51 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1604.txt 
rm -f result-1605.txt
echo "fi 1 3 51 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1605.txt 
rm -f result-1606.txt
echo "fi 1 3 51 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1606.txt 
rm -f result-1607.txt
echo "fi 1 3 51 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1607.txt 
rm -f result-1608.txt
echo "fi 1 3 51 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1608.txt 
rm -f result-1609.txt
echo "fi 1 3 51 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1609.txt 
rm -f result-1610.txt
echo "fi 1 3 52 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1610.txt 
rm -f result-1611.txt
echo "fi 1 3 52 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1611.txt 
rm -f result-1612.txt
echo "fi 1 3 52 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1612.txt 
rm -f result-1613.txt
echo "fi 1 3 52 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1613.txt 
rm -f result-1614.txt
echo "fi 1 3 52 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1614.txt 
rm -f result-1615.txt
echo "fi 1 3 52 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1615.txt 
rm -f result-1616.txt
echo "fi 1 3 52 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1616.txt 
rm -f result-1617.txt
echo "fi 1 3 53 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1617.txt 
rm -f result-1618.txt
echo "fi 1 3 53 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1618.txt 
rm -f result-1619.txt
echo "fi 1 3 53 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1619.txt 
rm -f result-1620.txt
echo "fi 1 3 53 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1620.txt 
rm -f result-1621.txt
echo "fi 1 3 53 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1621.txt 
rm -f result-1622.txt
echo "fi 1 3 53 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1622.txt 
rm -f result-1623.txt
echo "fi 1 3 53 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1623.txt 
rm -f result-1624.txt
echo "fi 1 3 54 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1624.txt 
rm -f result-1625.txt
echo "fi 1 3 54 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1625.txt 
rm -f result-1626.txt
echo "fi 1 3 54 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1626.txt 
rm -f result-1627.txt
echo "fi 1 3 54 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1627.txt 
rm -f result-1628.txt
echo "fi 1 3 54 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1628.txt 
rm -f result-1629.txt
echo "fi 1 3 54 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1629.txt 
rm -f result-1630.txt
echo "fi 1 3 54 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1630.txt 
rm -f result-1631.txt
echo "fi 1 3 55 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1631.txt 
rm -f result-1632.txt
echo "fi 1 3 55 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1632.txt 
rm -f result-1633.txt
echo "fi 1 3 55 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1633.txt 
rm -f result-1634.txt
echo "fi 1 3 55 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1634.txt 
rm -f result-1635.txt
echo "fi 1 3 55 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1635.txt 
rm -f result-1636.txt
echo "fi 1 3 55 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1636.txt 
rm -f result-1637.txt
echo "fi 1 3 55 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1637.txt 
rm -f result-1638.txt
echo "fi 1 3 56 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1638.txt 
rm -f result-1639.txt
echo "fi 1 3 56 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1639.txt 
rm -f result-1640.txt
echo "fi 1 3 56 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1640.txt 
rm -f result-1641.txt
echo "fi 1 3 56 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1641.txt 
rm -f result-1642.txt
echo "fi 1 3 56 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1642.txt 
rm -f result-1643.txt
echo "fi 1 3 56 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1643.txt 
rm -f result-1644.txt
echo "fi 1 3 56 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1644.txt 
rm -f result-1645.txt
echo "fi 1 3 57 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1645.txt 
rm -f result-1646.txt
echo "fi 1 3 57 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1646.txt 
rm -f result-1647.txt
echo "fi 1 3 57 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1647.txt 
rm -f result-1648.txt
echo "fi 1 3 57 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1648.txt 
rm -f result-1649.txt
echo "fi 1 3 57 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1649.txt 
rm -f result-1650.txt
echo "fi 1 3 57 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1650.txt 
rm -f result-1651.txt
echo "fi 1 3 57 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1651.txt 
rm -f result-1652.txt
echo "fi 1 3 58 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1652.txt 
rm -f result-1653.txt
echo "fi 1 3 58 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1653.txt 
rm -f result-1654.txt
echo "fi 1 3 58 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1654.txt 
rm -f result-1655.txt
echo "fi 1 3 58 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1655.txt 
rm -f result-1656.txt
echo "fi 1 3 58 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1656.txt 
rm -f result-1657.txt
echo "fi 1 3 58 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1657.txt 
rm -f result-1658.txt
echo "fi 1 3 58 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1658.txt 
rm -f result-1659.txt
echo "fi 1 3 59 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1659.txt 
rm -f result-1660.txt
echo "fi 1 3 59 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1660.txt 
rm -f result-1661.txt
echo "fi 1 3 59 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1661.txt 
rm -f result-1662.txt
echo "fi 1 3 59 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1662.txt 
rm -f result-1663.txt
echo "fi 1 3 59 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1663.txt 
rm -f result-1664.txt
echo "fi 1 3 59 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1664.txt 
rm -f result-1665.txt
echo "fi 1 3 59 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1665.txt 
rm -f result-1666.txt
echo "fi 1 3 60 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1666.txt 
rm -f result-1667.txt
echo "fi 1 3 60 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1667.txt 
rm -f result-1668.txt
echo "fi 1 3 60 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1668.txt 
rm -f result-1669.txt
echo "fi 1 3 60 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1669.txt 
rm -f result-1670.txt
echo "fi 1 3 60 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1670.txt 
rm -f result-1671.txt
echo "fi 1 3 60 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1671.txt 
rm -f result-1672.txt
echo "fi 1 3 60 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1672.txt 
rm -f result-1673.txt
echo "fi 1 3 61 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1673.txt 
rm -f result-1674.txt
echo "fi 1 3 61 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1674.txt 
rm -f result-1675.txt
echo "fi 1 3 61 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1675.txt 
rm -f result-1676.txt
echo "fi 1 3 61 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1676.txt 
rm -f result-1677.txt
echo "fi 1 3 61 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1677.txt 
rm -f result-1678.txt
echo "fi 1 3 61 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1678.txt 
rm -f result-1679.txt
echo "fi 1 3 61 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1679.txt 
rm -f result-1680.txt
echo "fi 1 3 62 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1680.txt 
rm -f result-1681.txt
echo "fi 1 3 62 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1681.txt 
rm -f result-1682.txt
echo "fi 1 3 62 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1682.txt 
rm -f result-1683.txt
echo "fi 1 3 62 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1683.txt 
rm -f result-1684.txt
echo "fi 1 3 62 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1684.txt 
rm -f result-1685.txt
echo "fi 1 3 62 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1685.txt 
rm -f result-1686.txt
echo "fi 1 3 62 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1686.txt 
rm -f result-1687.txt
echo "fi 1 3 63 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1687.txt 
rm -f result-1688.txt
echo "fi 1 3 63 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1688.txt 
rm -f result-1689.txt
echo "fi 1 3 63 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1689.txt 
rm -f result-1690.txt
echo "fi 1 3 63 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1690.txt 
rm -f result-1691.txt
echo "fi 1 3 63 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1691.txt 
rm -f result-1692.txt
echo "fi 1 3 63 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1692.txt 
rm -f result-1693.txt
echo "fi 1 3 63 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1693.txt 
rm -f result-1694.txt
echo "fi 1 3 64 127 0x80000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1694.txt 
rm -f result-1695.txt
echo "fi 1 3 64 127 0x40000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1695.txt 
rm -f result-1696.txt
echo "fi 1 3 64 127 0x08000000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1696.txt 
rm -f result-1697.txt
echo "fi 1 3 64 127 0x00800000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1697.txt 
rm -f result-1698.txt
echo "fi 1 3 64 127 0x00400000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1698.txt 
rm -f result-1699.txt
echo "fi 1 3 64 127 0x00001000 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1699.txt 
rm -f result-1700.txt
echo "fi 1 3 64 127 0x00000001 int kIndex1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1700.txt 
rm -f result-1701.txt
echo "fi 1 3 65 127 0x80000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1701.txt 
rm -f result-1702.txt
echo "fi 1 3 65 127 0x40000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1702.txt 
rm -f result-1703.txt
echo "fi 1 3 65 127 0x08000000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1703.txt 
rm -f result-1704.txt
echo "fi 1 3 65 127 0x00800000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1704.txt 
rm -f result-1705.txt
echo "fi 1 3 65 127 0x00400000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1705.txt 
rm -f result-1706.txt
echo "fi 1 3 65 127 0x00001000 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1706.txt 
rm -f result-1707.txt
echo "fi 1 3 65 127 0x00000001 fp expArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1707.txt 
rm -f result-1708.txt
echo "fi 1 3 66 127 0x80000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1708.txt 
rm -f result-1709.txt
echo "fi 1 3 66 127 0x40000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1709.txt 
rm -f result-1710.txt
echo "fi 1 3 66 127 0x08000000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1710.txt 
rm -f result-1711.txt
echo "fi 1 3 66 127 0x00800000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1711.txt 
rm -f result-1712.txt
echo "fi 1 3 66 127 0x00400000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1712.txt 
rm -f result-1713.txt
echo "fi 1 3 66 127 0x00001000 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1713.txt 
rm -f result-1714.txt
echo "fi 1 3 66 127 0x00000001 fp cosArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1714.txt 
rm -f result-1715.txt
echo "fi 1 3 67 127 0x80000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1715.txt 
rm -f result-1716.txt
echo "fi 1 3 67 127 0x40000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1716.txt 
rm -f result-1717.txt
echo "fi 1 3 67 127 0x08000000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1717.txt 
rm -f result-1718.txt
echo "fi 1 3 67 127 0x00800000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1718.txt 
rm -f result-1719.txt
echo "fi 1 3 67 127 0x00400000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1719.txt 
rm -f result-1720.txt
echo "fi 1 3 67 127 0x00001000 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1720.txt 
rm -f result-1721.txt
echo "fi 1 3 67 127 0x00000001 fp sinArg1" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1721.txt 
rm -f result-1722.txt
echo "fi 1 3 68 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1722.txt 
rm -f result-1723.txt
echo "fi 1 3 68 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1723.txt 
rm -f result-1724.txt
echo "fi 1 3 68 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1724.txt 
rm -f result-1725.txt
echo "fi 1 3 68 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1725.txt 
rm -f result-1726.txt
echo "fi 1 3 68 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1726.txt 
rm -f result-1727.txt
echo "fi 1 3 68 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1727.txt 
rm -f result-1728.txt
echo "fi 1 3 68 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1728.txt 
rm -f result-1729.txt
echo "fi 1 3 69 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1729.txt 
rm -f result-1730.txt
echo "fi 1 3 69 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1730.txt 
rm -f result-1731.txt
echo "fi 1 3 69 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1731.txt 
rm -f result-1732.txt
echo "fi 1 3 69 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1732.txt 
rm -f result-1733.txt
echo "fi 1 3 69 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1733.txt 
rm -f result-1734.txt
echo "fi 1 3 69 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1734.txt 
rm -f result-1735.txt
echo "fi 1 3 69 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1735.txt 
rm -f result-1736.txt
echo "fi 1 3 70 127 0x80000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1736.txt 
rm -f result-1737.txt
echo "fi 1 3 70 127 0x40000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1737.txt 
rm -f result-1738.txt
echo "fi 1 3 70 127 0x08000000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1738.txt 
rm -f result-1739.txt
echo "fi 1 3 70 127 0x00800000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1739.txt 
rm -f result-1740.txt
echo "fi 1 3 70 127 0x00400000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1740.txt 
rm -f result-1741.txt
echo "fi 1 3 70 127 0x00001000 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1741.txt 
rm -f result-1742.txt
echo "fi 1 3 70 127 0x00000001 int kIndex2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1742.txt 
rm -f result-1743.txt
echo "fi 1 3 71 127 0x80000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1743.txt 
rm -f result-1744.txt
echo "fi 1 3 71 127 0x40000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1744.txt 
rm -f result-1745.txt
echo "fi 1 3 71 127 0x08000000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1745.txt 
rm -f result-1746.txt
echo "fi 1 3 71 127 0x00800000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1746.txt 
rm -f result-1747.txt
echo "fi 1 3 71 127 0x00400000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1747.txt 
rm -f result-1748.txt
echo "fi 1 3 71 127 0x00001000 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1748.txt 
rm -f result-1749.txt
echo "fi 1 3 71 127 0x00000001 fp expArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1749.txt 
rm -f result-1750.txt
echo "fi 1 3 72 127 0x80000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1750.txt 
rm -f result-1751.txt
echo "fi 1 3 72 127 0x40000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1751.txt 
rm -f result-1752.txt
echo "fi 1 3 72 127 0x08000000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1752.txt 
rm -f result-1753.txt
echo "fi 1 3 72 127 0x00800000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1753.txt 
rm -f result-1754.txt
echo "fi 1 3 72 127 0x00400000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1754.txt 
rm -f result-1755.txt
echo "fi 1 3 72 127 0x00001000 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1755.txt 
rm -f result-1756.txt
echo "fi 1 3 72 127 0x00000001 fp cosArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1756.txt 
rm -f result-1757.txt
echo "fi 1 3 73 127 0x80000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1757.txt 
rm -f result-1758.txt
echo "fi 1 3 73 127 0x40000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1758.txt 
rm -f result-1759.txt
echo "fi 1 3 73 127 0x08000000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1759.txt 
rm -f result-1760.txt
echo "fi 1 3 73 127 0x00800000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1760.txt 
rm -f result-1761.txt
echo "fi 1 3 73 127 0x00400000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1761.txt 
rm -f result-1762.txt
echo "fi 1 3 73 127 0x00001000 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1762.txt 
rm -f result-1763.txt
echo "fi 1 3 73 127 0x00000001 fp sinArg2" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1763.txt 
rm -f result-1764.txt
echo "fi 1 3 74 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1764.txt 
rm -f result-1765.txt
echo "fi 1 3 74 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1765.txt 
rm -f result-1766.txt
echo "fi 1 3 74 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1766.txt 
rm -f result-1767.txt
echo "fi 1 3 74 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1767.txt 
rm -f result-1768.txt
echo "fi 1 3 74 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1768.txt 
rm -f result-1769.txt
echo "fi 1 3 74 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1769.txt 
rm -f result-1770.txt
echo "fi 1 3 74 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1770.txt 
rm -f result-1771.txt
echo "fi 1 3 75 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1771.txt 
rm -f result-1772.txt
echo "fi 1 3 75 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1772.txt 
rm -f result-1773.txt
echo "fi 1 3 75 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1773.txt 
rm -f result-1774.txt
echo "fi 1 3 75 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1774.txt 
rm -f result-1775.txt
echo "fi 1 3 75 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1775.txt 
rm -f result-1776.txt
echo "fi 1 3 75 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1776.txt 
rm -f result-1777.txt
echo "fi 1 3 75 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1777.txt 
rm -f result-1778.txt
echo "fi 1 3 76 127 0x80000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1778.txt 
rm -f result-1779.txt
echo "fi 1 3 76 127 0x40000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1779.txt 
rm -f result-1780.txt
echo "fi 1 3 76 127 0x08000000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1780.txt 
rm -f result-1781.txt
echo "fi 1 3 76 127 0x00800000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1781.txt 
rm -f result-1782.txt
echo "fi 1 3 76 127 0x00400000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1782.txt 
rm -f result-1783.txt
echo "fi 1 3 76 127 0x00001000 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1783.txt 
rm -f result-1784.txt
echo "fi 1 3 76 127 0x00000001 int kIndex3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1784.txt 
rm -f result-1785.txt
echo "fi 1 3 77 127 0x80000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1785.txt 
rm -f result-1786.txt
echo "fi 1 3 77 127 0x40000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1786.txt 
rm -f result-1787.txt
echo "fi 1 3 77 127 0x08000000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1787.txt 
rm -f result-1788.txt
echo "fi 1 3 77 127 0x00800000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1788.txt 
rm -f result-1789.txt
echo "fi 1 3 77 127 0x00400000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1789.txt 
rm -f result-1790.txt
echo "fi 1 3 77 127 0x00001000 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1790.txt 
rm -f result-1791.txt
echo "fi 1 3 77 127 0x00000001 fp expArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1791.txt 
rm -f result-1792.txt
echo "fi 1 3 78 127 0x80000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1792.txt 
rm -f result-1793.txt
echo "fi 1 3 78 127 0x40000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1793.txt 
rm -f result-1794.txt
echo "fi 1 3 78 127 0x08000000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1794.txt 
rm -f result-1795.txt
echo "fi 1 3 78 127 0x00800000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1795.txt 
rm -f result-1796.txt
echo "fi 1 3 78 127 0x00400000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1796.txt 
rm -f result-1797.txt
echo "fi 1 3 78 127 0x00001000 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1797.txt 
rm -f result-1798.txt
echo "fi 1 3 78 127 0x00000001 fp cosArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1798.txt 
rm -f result-1799.txt
echo "fi 1 3 79 127 0x80000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1799.txt 
rm -f result-1800.txt
echo "fi 1 3 79 127 0x40000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1800.txt 
rm -f result-1801.txt
echo "fi 1 3 79 127 0x08000000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1801.txt 
rm -f result-1802.txt
echo "fi 1 3 79 127 0x00800000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1802.txt 
rm -f result-1803.txt
echo "fi 1 3 79 127 0x00400000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1803.txt 
rm -f result-1804.txt
echo "fi 1 3 79 127 0x00001000 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1804.txt 
rm -f result-1805.txt
echo "fi 1 3 79 127 0x00000001 fp sinArg3" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1805.txt 
rm -f result-1806.txt
echo "fi 1 3 80 127 0x80000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1806.txt 
rm -f result-1807.txt
echo "fi 1 3 80 127 0x40000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1807.txt 
rm -f result-1808.txt
echo "fi 1 3 80 127 0x08000000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1808.txt 
rm -f result-1809.txt
echo "fi 1 3 80 127 0x00800000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1809.txt 
rm -f result-1810.txt
echo "fi 1 3 80 127 0x00400000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1810.txt 
rm -f result-1811.txt
echo "fi 1 3 80 127 0x00001000 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1811.txt 
rm -f result-1812.txt
echo "fi 1 3 80 127 0x00000001 fp sOutR" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1812.txt 
rm -f result-1813.txt
echo "fi 1 3 81 127 0x80000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1813.txt 
rm -f result-1814.txt
echo "fi 1 3 81 127 0x40000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1814.txt 
rm -f result-1815.txt
echo "fi 1 3 81 127 0x08000000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1815.txt 
rm -f result-1816.txt
echo "fi 1 3 81 127 0x00800000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1816.txt 
rm -f result-1817.txt
echo "fi 1 3 81 127 0x00400000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1817.txt 
rm -f result-1818.txt
echo "fi 1 3 81 127 0x00001000 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1818.txt 
rm -f result-1819.txt
echo "fi 1 3 81 127 0x00000001 fp sOutI" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1819.txt 
rm -f result-1820.txt
echo "fi 1 3 82 0 0x80000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1820.txt 
rm -f result-1821.txt
echo "fi 1 3 82 0 0x40000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1821.txt 
rm -f result-1822.txt
echo "fi 1 3 82 0 0x08000000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1822.txt 
rm -f result-1823.txt
echo "fi 1 3 82 0 0x00800000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1823.txt 
rm -f result-1824.txt
echo "fi 1 3 82 0 0x00400000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1824.txt 
rm -f result-1825.txt
echo "fi 1 3 82 0 0x00001000 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1825.txt 
rm -f result-1826.txt
echo "fi 1 3 82 0 0x00000001 fp outR[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1826.txt 
rm -f result-1827.txt
echo "fi 1 3 83 0 0x80000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1827.txt 
rm -f result-1828.txt
echo "fi 1 3 83 0 0x40000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1828.txt 
rm -f result-1829.txt
echo "fi 1 3 83 0 0x08000000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1829.txt 
rm -f result-1830.txt
echo "fi 1 3 83 0 0x00800000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1830.txt 
rm -f result-1831.txt
echo "fi 1 3 83 0 0x00400000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1831.txt 
rm -f result-1832.txt
echo "fi 1 3 83 0 0x00001000 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1832.txt 
rm -f result-1833.txt
echo "fi 1 3 83 0 0x00000001 fp outI[xIndex]" > benchmarks/mri-fhd/fi_cmd.txt
cat benchmarks/mri-fhd/fi_cmd.txt
./parboil run mri-fhd cuda_fi large > result-1833.txt 
