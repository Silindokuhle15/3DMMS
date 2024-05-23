#pragma once
#include "Mesh.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "pch.h"

class QuadrupedDynamics
{
public:
	uint32_t m_CurrentFrame;
	uint32_t m_NumberofFrames;
	std::vector<std::string> m_FirstStereoPairFileNames;
	std::vector<Mesh> m_Frames;

	QuadrupedDynamics(std::vector<std::string> path_to_frames) :
		m_CurrentFrame{0},
		m_NumberofFrames{0}
	{
		for (auto str : path_to_frames)
		{
			ConstuctFrameFromFile(str);
		}
	}
	QuadrupedDynamics(std::string path_to_frames) :
		m_CurrentFrame{0},
		m_NumberofFrames{ 0 }
	{
		ConstuctFrameFromFile(path_to_frames);
	}

	void ConstuctFrameFromFile(std::string csv_filepath)
	{

		io::CSVReader<3> cam1_reader(csv_filepath.c_str());
		//io::CSVReader<3> cam2_reader(path_to_files[1]);

		//cam1_reader.read_header(io::ignore_missing_column, "A", "B", "C");

		mycsvfields  csv_field;
		auto readCSVFunc = [](io::CSVReader<3>& reader, mycsvfields& view)
			{
				return reader.read_row(view.x, view.y, view.z);
			};

		std::vector<glm::vec3> vertex_data;

		while (readCSVFunc(cam1_reader, csv_field))
		{
			// CHECK FOR EMPTY FIELD
			double x, y, z;
			x = std::atof(csv_field.x.c_str());
			y = std::atof(csv_field.y.c_str());
			z = std::atof(csv_field.z.c_str());
			//m_Frames[m_CurrentFrame].push_back(Vertex{glm::vec3(x, y,z),{0.0, 0.0}, {1},{0.0, 1.0, 0.0}});
			vertex_data.push_back(glm::vec3(x, y,z));
		}
		//m_Frames.push_back(Mesh(vertex_data));
		//m_NumberofFrames++;
		// NOW AUGMENT THE VERTICES TO FORM THE MODEL OF THE QUADRUPED
		std::vector<Vertex> m_augment_vertex_data;

		

		m_augment_vertex_data.push_back(Vertex{ vertex_data[0], { 0.0, 0.0 }, 1, { 0.50, 0, 1.0 } });// nose
		m_augment_vertex_data.push_back(Vertex{ vertex_data[1], {0.0, 0.0 }, 1, {0.39, 0.98, 0.76} }); // throat_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[2], {0.0, 0.0 }, 1, {0.56, 1.0, 0.73} }); // throat_end
		m_augment_vertex_data.push_back(Vertex{ vertex_data[3], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[6], {0.0, 0.0 }, 1, {0.76, 0.92, 0.55} }); // front_left_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[5], {0.0, 0.0 }, 1, {0.82, 0.88, 0.51} }); // front_left_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[4], {0.0, 0.0 }, 1, {0.87, 0.84, 0.47} }); // front_left_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[3], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[9], {0.0, 0.0 }, 1, {0.92, 0.79, 0.44} }); // front_right_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[8], {0.0, 0.0 }, 1, {0.98, 0.73, 0.40} }); // front_right_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[7], {0.0, 0.0 }, 1, {1.0, 0.67, 0.36} }); // front_right_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[3], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		//m_augment_vertex_data.push_back(Vertex{ vertex_data[10], {0.0, 0.0 }, 1, {0.61, 0.98, 0.65} }); // back_middle
		m_augment_vertex_data.push_back(Vertex{ vertex_data[11], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base

		//m_augment_vertex_data.push_back(Vertex{ vertex_data[11], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[14], {0.0, 0.0 }, 1, {1.0, 0.47, 0.65} }); // back_left_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[13], {0.0, 0.0 }, 1, {1.0, 0.40, 0.20} }); // back_left_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[12], {0.0, 0.0 }, 1, {1.0, 0.61, 0.32} }); // back_left_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[11], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[17], {0.0, 0.0 }, 1, {1.0, 0.47, 0.24} }); // back_right_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[16], {0.0, 0.0 }, 1, {1.0, 0.31, 0.16} }); // back_right_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[15], {0.0, 0.0 }, 1, {1.0, 0.24, 0.12} }); // back_right_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[11], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[18], {0.0, 0.0 }, 1, {0.71, 0.95, 0.58} }); // tail_end
		
		
		/*
		m_augment_vertex_data.push_back(Vertex{ vertex_data[0], {0.0, 0.0 }, 1, {0.50, 0, 1.0} });  // nose
		m_augment_vertex_data.push_back(Vertex{ vertex_data[17], {0.0, 0.0 }, 1, {0.39, 0.98, 0.76} }); // throat_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[18], {0.0, 0.0 }, 1, {0.56, 1.0, 0.73} }); // throat_end
		m_augment_vertex_data.push_back(Vertex{ vertex_data[19], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base

		//m_augment_vertex_data.push_back(vertex	_data[20]); // back_end
		//m_augment_vertex_data.push_back(vertex_data[21]); // back_middle
		//m_augment_vertex_data.push_back(vertex_data[22]); // tail_base
		//m_augment_vertex_data.push_back(vertex_data[23]); // tail_end

		m_augment_vertex_data.push_back(Vertex{ vertex_data[19], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[24], {0.0, 0.0 }, 1, {0.76, 0.92, 0.55} }); // front_left_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[25], {0.0, 0.0 }, 1, {0.82, 0.88, 0.51} }); // front_left_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[26], {0.0, 0.0 }, 1, {0.87, 0.84, 0.47} }); // front_left_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[19], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[27], {0.0, 0.0 }, 1, {0.92, 0.79, 0.44} }); // front_right_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[28], {0.0, 0.0 }, 1, {0.98, 0.73, 0.40} }); // front_right_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[29], {0.0, 0.0 }, 1, {1.0, 0.67, 0.36} }); // front_right_paw


		m_augment_vertex_data.push_back(Vertex{ vertex_data[19], {0.0, 0.0 }, 1, {0.50, 1.0, 0.71} }); // back_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[21], {0.0, 0.0 }, 1, {0.61, 0.98, 0.65} }); // back_middle
		m_augment_vertex_data.push_back(Vertex{ vertex_data[22], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base

		//m_augment_vertex_data.push_back(vertex_data[36]); // belly_bottom

		//m_augment_vertex_data.push_back(vertex_data[21]); // back_middle
		//m_augment_vertex_data.push_back(vertex_data[37]); // body_middle_right

		//m_augment_vertex_data.push_back(vertex_data[19]); // back_middle
		//m_augment_vertex_data.push_back(vertex_data[38]); // body_middle_left

		m_augment_vertex_data.push_back(Vertex{ vertex_data[22], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[31], {0.0, 0.0 }, 1, {1.0, 0.47, 0.65} }); // back_left_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[33], {0.0, 0.0 }, 1, {1.0, 0.40, 0.20} }); // back_left_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[30], {0.0, 0.0 }, 1, {1.0, 0.61, 0.32} }); // back_left_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[22], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[32], {0.0, 0.0 }, 1, {1.0, 0.47, 0.24} }); // back_right_thai
		m_augment_vertex_data.push_back(Vertex{ vertex_data[34], {0.0, 0.0 }, 1, {1.0, 0.31, 0.16} }); // back_right_knee
		m_augment_vertex_data.push_back(Vertex{ vertex_data[35], {0.0, 0.0 }, 1, {1.0, 0.24, 0.12} }); // back_right_paw

		m_augment_vertex_data.push_back(Vertex{ vertex_data[22], {0.0, 0.0 }, 1, {0.66, 0.97, 0.32} }); // tail_base
		m_augment_vertex_data.push_back(Vertex{ vertex_data[23], {0.0, 0.0 }, 1, {0.71, 0.95, 0.58} }); // tail_end
		
		*/
		uint32_t NumIndices = m_augment_vertex_data.size();
		uint32_t NumVertices = m_augment_vertex_data.size();

		m_Frames.push_back(Mesh(m_augment_vertex_data));
		m_NumberofFrames++;
	}

	QuadrupedDynamics() :
		m_CurrentFrame{ 0 },
		m_NumberofFrames{ 0 }
	{
		// INITIALIZE THE MODEL IN THE STANDARD QUADRUPED POSE
		std::vector<Vertex> temp;
		
		temp.push_back(Vertex{ glm::vec3(0, 1.0, 0), { 0.0, 0.0 }, { 1 }, { 0.50, 0, 1.0 } });
		temp.push_back(Vertex{ glm::vec3(0.0, 1.1, -0.1), { 0.0, 0.0 }, { 1 }, {0.39, 0.98, 0.76} });
		temp.push_back(Vertex{ glm::vec3(0.0, 1.25, -0.2), { 0.0, 0.0 }, { 1 }, {0.56, 1.0, 0.73} });
		temp.push_back(Vertex{ glm::vec3(0.0, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.50, 1.0, 0.71} });

		//temp.push_back(Vertex{ glm::vec3(0.0, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.50, 1.0, 0.71} });
		temp.push_back(Vertex{ glm::vec3(-0.5, 2.0, -2.7), { 0.0, 0.0 }, { 1 }, {0.87, 0.84, 0.47} });
		temp.push_back(Vertex{ glm::vec3(-0.5, 2.0, -2.0), { 0.0, 0.0 }, { 1 }, {0.82, 0.88, 0.51}});
		temp.push_back(Vertex{ glm::vec3(-0.5, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.76, 0.92, 0.55} });

		temp.push_back(Vertex{ glm::vec3(0.0, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.50, 1.0, 0.71} });
		temp.push_back(Vertex{ glm::vec3(+0.5, 2.0, -2.7), { 0.0, 0.0 }, { 1 }, {1.0, 0.67, 0.36} });
		temp.push_back(Vertex{ glm::vec3(+0.5, 2.0, -2.0), { 0.0, 0.0 }, { 1 }, {0.98, 0.73, 0.40}});
		temp.push_back(Vertex{ glm::vec3(+0.5, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.92, 0.79, 0.44} });
		
		temp.push_back(Vertex{ glm::vec3(0.0, 2.0, -1.5), { 0.0, 0.0 }, { 1 }, {0.50, 1.0, 0.71} });
		//temp.push_back(Vertex{ glm::vec3(0.0, 3.0, -1.52), { 0.0, 0.0 }, { 1 },{0.61, 0.98, 0.65}});
		temp.push_back(Vertex{ glm::vec3(0.0, 4.2, -1.5), { 0.0, 0.0 }, { 1 }, {0.66, 0.97, 0.32}});

		//temp.push_back(Vertex{ glm::vec3(0.0, 4.2, -1.5), { 0.0, 0.0 }, { 1 }, {0.61, 0.98, 0.65} });
		temp.push_back(Vertex{ glm::vec3(-0.5, 4.0, -2.7), { 0.0, 0.0 }, { 1 }, {1.0, 0.61, 0.32} });
		temp.push_back(Vertex{ glm::vec3(-0.5, 4.0, -2.0), { 0.0, 0.0 }, { 1 }, {1.0, 0.40, 0.20}});
		temp.push_back(Vertex{ glm::vec3(-0.5, 4.0, -1.5), { 0.0, 0.0 }, { 1 }, {1.0, 0.47, 0.65} });

		temp.push_back(Vertex{ glm::vec3(0.0, 4.2, -1.5), { 0.0, 0.0 }, { 1 }, {0.61, 0.98, 0.65} });
		
		temp.push_back(Vertex{ glm::vec3(+0.5, 4.0, -2.7), { 0.0, 0.0 }, { 1 }, {1.0, 0.24, 0.12} });
		temp.push_back(Vertex{ glm::vec3(+0.5, 4.0, -2.0), { 0.0, 0.0 }, { 1 }, {1.0, 0.31, 0.16}});
		temp.push_back(Vertex{ glm::vec3(+0.5, 4.0, -1.5), { 0.0, 0.0 }, { 1 }, {1.0, 0.47, 0.24} });
		
		temp.push_back(Vertex{ glm::vec3(0.0, 4.2, -1.5), { 0.0, 0.0 }, { 1 }, {0.61, 0.98, 0.65} });
		temp.push_back(Vertex{ glm::vec3(0.0, 4.5, -1.6), { 0.0, 0.0 }, { 1 }, {0.71, 0.95, 0.58} });

		uint32_t NumIndices = temp.size();
		uint32_t NumVertices = temp.size();

		m_Frames.push_back(Mesh(temp));
		m_NumberofFrames++;
	}

	void AdvanceFrame();
	Mesh GetCurrentFrame() { return m_Frames[m_CurrentFrame]; }

};