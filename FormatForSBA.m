
% Do SBA for all frames
% Specify the directory path
directoryPath = uigetdir('3d_points/cam1_and_cam2');

% Specify the desired file extension (e.g., '.txt', '.csv', '.bmp', etc.)
fileExtension = '.csv'; % Change this to your desired extension

% Get a list of files with the specified extension in the directory
fileList = dir(fullfile(directoryPath, ['*' fileExtension]));

% Count the number of files
numFiles = numel(fileList);

% Create a cell array to store the file names
fileNames = cell(numFiles, 1);
for i = 1:numFiles
    fileNames{i} = fileList(i).name;
end

% Display the results
fprintf('Number of %s files in the directory: %d\n', fileExtension, numFiles);
fprintf('File names:\n');
disp(fileNames);

% Optionally, save the file names to a text file
% Uncomment the following lines if you want to save the list to a file
% outputFile = 'file_names.txt';
% fid = fopen(outputFile, 'w');
% fprintf(fid, '%s\n', fileNames{:});
% fclose(fid);
% fprintf('File names saved to %s\n', outputFile);

% Define the folders
folders_xyz = {'3d_points/cam1_and_cam2/', '3d_points/cam1_and_cam2/'};  % Replace with your folder names
folders_xy = {'/Data/', '/Data/'};  % Replace with your folder names

observations = ["Data/CollectedData_Silindokuhle_cam1_fill.csv";...
    "Data/CollectedData_Silindokuhle_cam2_fill.csv"];

for i=1: length(fileNames)
    path = fileNames{i};
    ConstructObservationMatrix(path, observations);

end

function observationMatrix = ConstructObservationMatrix(path_to_frame, cam_observations)
% Read the data from the first .csv file
    data1 = csvread(path_to_frame);

    output_filename = split(path_to_frame, '.', 1);
    output_filename = output_filename(1) + ".txt";

% Read the data from the second and third .csv files
    obs1 = cam_observations(1);
    obs2 = cam_observations(2);
    data2 = csvread(obs1);
    data3 = csvread(obs2);

% Initialize an empty matrix for the observation matrix

% Initialize an empty matrix for the observation matrix
    observationMatrix = [];

% Loop over each row (assuming data1, data2, and data3 have the same number of rows)
    for i = 1:size(data1, 1)
    % Extract the X, Y, Z coordinates from data1 (3D world points)
        X = data1(i, 1);
        Y = data1(i, 2);
        Z = data1(i, 3);

    % Extract the x, y coordinates from data2 (camera 1)
        x_cam1 = data2(i, 1);
        y_cam1 = data2(i, 2);

    % Extract the x, y coordinates from data3 (camera 2)
        x_cam2 = data3(i, 1);
        y_cam2 = data3(i, 2);

    % Create a single row combining all information
        row = [X, Y, Z, 2, 0, x_cam1, y_cam1, 1, x_cam2, y_cam2];

    % Append the row to the observation matrix
        observationMatrix = [observationMatrix; row];
    end

% Save the observation matrix to a text file (optional)
    dlmwrite(output_filename, observationMatrix, 'delimiter', '\t');

    disp('Observation matrix created and saved.');
end