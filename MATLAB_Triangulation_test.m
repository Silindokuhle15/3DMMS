% TRIANGULATION TEST SCRIPT
cam1_data = readtable("calibrated_dog1_cam4_dlc_labelled.csv");
cam2_data = readtable("calibrated_dog1_cam6_dlc_labelled.csv");

cam1_frame1 = cam1_data(1, 1:end);
cam2_frame1 = cam2_data(1, 1:end);

N = size(cam2_data);
N = N(1);
for i=1:N
    cam1_frame = table2array(cam1_data(i, 1:end));
    cam2_frame = table2array(cam2_data(i, 1:end));

    p1 = reshape(cam1_frame, [39, 2]);
    p2 = reshape(cam2_frame, [39, 2]);

    [framexyzPoints, frameprojectErrors, framevalidIndex] = triangulate(p1, p2, stereoParams46);
    framexyzPoints = framexyzPoints / 1000; % Convert from Millimeters to meters
    filename = "3d_points_frame_"+string(i);
    save(filename, "framexyzPoints");
    csvwrite(filename + ".csv", framexyzPoints);

end