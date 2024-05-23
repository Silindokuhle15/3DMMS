% Define the directory where the .csv files are stored
directory = '3d_points/cam1_and_cam2/'; % Replace with your directory

% Get a list of all .csv files in the directory
files = dir(fullfile(directory, '*.csv'));

% Define the neutral pose
neutral_pose = [[0, 1.0, 0];... % Your neutral pose
		[0.0, 1.1, -0.1];...
		[0.0, 1.25, -0.2];...
		[0.0, 2.0, -1.5];...
		[-0.5, 2.0, -1.5];...
		[-0.5, 2.0, -2.0];...
		[-0.5, 2.0, -2.7];...
		[+0.5, 2.0, -1.5];...
		[+0.5, 2.0, -2.0];...
		[+0.5, 2.0, -2.7];...
		[0.0, 3.0, -1.52];...
		[-0.5, 4.0, -1.5];...
		[-0.5, 4.0, -2.0];...
		[-0.5, 4.0, -2.7];...
		[+0.5, 4.0, -1.5];...
		[+0.5, 4.0, -2.0];...
		[+0.5, 4.0, -2.7];...
        [+0.0, 4.0, -1.52];...
        [+0.0, 4.5, -2.4];...
];

% Define the joint pairs
joint_pairs = [[1, 2]; ... % Each row is a pair of joints [joint1, joint2]
    [2, 3];... % throat_base-throad-end
    [3, 4];....% throat_end-back_base
    [4, 5];... % back_base-front_left_thai
    [5, 6];...
    [6, 7];...
    [4, 8];... % back_base-front_right_thai
    [8, 9];...
    [9, 10];...
    [4, 11];... % back_base-torso
    [11, 12];... % torso-tail_base
    [12, 13];... % tail_base-back_left_thai
    [13, 14];...
    [14, 15];...
    [12, 16];... % tail_base-back_right_thai
    [16, 17];...
    [17, 18];...
    [12, 19];... % tail_base-tail_end
    ];

distances = [norm(neutral_pose(1) - neutral_pose(2)), ... % Corresponding distances between the joint pairs in the neutral pose
    norm(neutral_pose(2) - neutral_pose(3)), ...
    norm(neutral_pose(3) - neutral_pose(4)), ... % throat_end-back_base
    norm(neutral_pose(4) - neutral_pose(5)), ... 
    norm(neutral_pose(5) - neutral_pose(6)), ...
    norm(neutral_pose(6) - neutral_pose(7)), ...
    norm(neutral_pose(4) - neutral_pose(8)), ... % back_base-front_right_thai
    norm(neutral_pose(8) - neutral_pose(9)), ...
    norm(neutral_pose(9) - neutral_pose(10)), ...
    norm(neutral_pose(4) - neutral_pose(11)), ...
    norm(neutral_pose(11) - neutral_pose(12)), ...
    norm(neutral_pose(12) - neutral_pose(13)), ...
    norm(neutral_pose(13) - neutral_pose(14)), ...
    norm(neutral_pose(14) - neutral_pose(15)), ...
    norm(neutral_pose(12) - neutral_pose(16)), ...
    norm(neutral_pose(16) - neutral_pose(17)), ...
    norm(neutral_pose(17) - neutral_pose(18)), ...
    norm(neutral_pose(12) - neutral_pose(19)), ...
    ];

% Define the neutral pose angles
neutral_angles = calculate_angles(neutral_pose, joint_pairs);

% Loop over each file
for i = 1:length(files)
    % Read the initial pose from the .csv file
    initial_pose = csvread(fullfile(directory, files(i).name));

    % Define the cost function
    cost_function = @(pose) sum_of_distances(pose, joint_pairs);

    % Create the constraints function with the specific joint_pairs and distances
    constraints_function = create_constraints(joint_pairs, distances, neutral_angles);

    % Set up the optimization problem
    options = optimoptions('fmincon', 'Algorithm', 'interior-point');
    problem = createOptimProblem('fmincon', 'objective', cost_function, 'x0', initial_pose, 'nonlcon', constraints_function, 'options', options);

    % Solve the optimization problem
    [refined_pose, fval] = fmincon(problem);

    % Save the refined pose to a new .csv file
    csvwrite(fullfile(directory, ['refined_' files(i).name]), refined_pose);
end

% Define the sum of distances function
function total_distance = sum_of_distances(pose, joint_pairs)
    total_distance = 0;
    for i = 1:size(joint_pairs, 1)
        % For each pair of joints, calculate the distance in the current pose
        joint1 = pose(joint_pairs(i, 1), :);
        joint2 = pose(joint_pairs(i, 2), :);
        distance = norm(joint1 - joint2);
        total_distance = total_distance + distance;
    end
end

% Define the non-linear constraints function
function [c, ceq] = create_constraints(joint_pairs, distances, neutral_angles)
    function [c, ceq] = constraints(pose)
        c = []; % No inequality constraints
        ceq = []; % Initialize the equality constraints
        for i = 1:size(joint_pairs, 1)
            % For each pair of joints, calculate the distance in the current pose
            joint1 = pose(joint_pairs(i, 1), :);
            joint2 = pose(joint_pairs(i, 2), :);
            distance = norm(joint1 - joint2);
            % The difference between this distance and the distance in the neutral pose should be zero
            ceq = [ceq; distance - distances(i)];
        end
        for i = 1:size(joint_pairs, 1)-1
            % For each pair of joints, calculate the angle in the current pose
            joint1 = pose(joint_pairs(i, 1), :);
            joint2 = pose(joint_pairs(i, 2), :);
            joint3 = pose(joint_pairs(i+1, 2), :);
            angle = acos(dot(joint2-joint1, joint3-joint2) / (norm(joint2-joint1)*norm(joint3-joint2)));
            % The difference between this angle and the angle in the neutral pose should be zero
            ceq = [ceq; angle - neutral_angles(i)];
        end
    end
    c = @constraints;
end

% Define the function to calculate angles
function angles = calculate_angles(pose, joint_pairs)
    angles = zeros(size(joint_pairs, 1)-1, 1);
    for i = 1:size(joint_pairs, 1)-1
        % For each pair of joints, calculate the angle in the neutral pose
        joint1 = pose(joint_pairs(i, 1), :);
        joint2 = pose(joint_pairs(i, 2), :);
        joint3 = pose(joint_pairs(i+1, 2), :);
        angle = acos(dot(joint2-joint1, joint3-joint2) / (norm(joint2-joint1)*norm(joint3-joint2)));
        angles(i) = angle;
    end
end
