#include "3DMMS.h"

int main(int argc, char* argv[])
{
	int width = 1920, height = 1080;
	MyApplication  app(width, height, "3DMMS");
	Mesh m_sq[] = { 
		Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj")
	};
	/* 	
	sq2.m_Transform = glm::mat4(0.7902, -0.0766, 0.6080, 2.5766e+03,
		0.0171, 0.9945, 0.1030, 478.0687,
		-0.6126, -0.0710, 0.7872, 7.0036e+03,
		0, 0, 0, 1
	);
	*/
	for (int i = 0; i < ARRAYSIZE(m_sq); i++)
	{
		float sc = 0.5f, alpha = 1.5f;
		float xm = ARRAYSIZE(m_sq) / 2;
		m_sq[i].m_Transform = glm::scale(glm::mat4(1.0f), glm::vec3(sc, sc, sc));
		m_sq[i].m_Transform = glm::translate(m_sq[i].m_Transform, glm::vec3((i-xm)*(1+alpha), 0.0f, ARRAYSIZE(m_sq)));
		m_sq[i].OnInit();
	}

	uint32_t MAX_NUM_VERTICES = 100000;
	//glDisable(GL_CULL_FACE);

	unsigned int vBuf, iBuf;
	glGenBuffers(1, &vBuf);
	glGenBuffers(1, &iBuf);

	glBindBuffer(GL_ARRAY_BUFFER, vBuf);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuf);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * MAX_NUM_VERTICES, nullptr, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * MAX_NUM_VERTICES, nullptr, GL_STATIC_DRAW);

	uint32_t vShader, fShader, program;

	program = glCreateProgram();
	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vShaderSource = "#version 450 core\n"
		"layout(location = 0) in  vec3 Position;\n"
		"layout(location = 1) in  vec2 TexCoord;\n"
		"layout(location = 2) in  uint ID;\n"
		"layout(location = 3) in  vec3 Normal;\n"

		"uniform mat4 VP;\n"
		"uniform mat4 Model;\n"
		"uniform float delta;\n"

		"out VS_OUT\n"
		"{\n"
		"vec2 TexCoord;\n"
		"uint ID;\n"
		"vec3 Normal;\n"
		"}vs_out;\n"
		"void main()\n"
		"{\n"
		"gl_Position =  VP * Model * vec4(Position, 1.0f) * delta;\n"
		"vs_out.TexCoord = TexCoord;\n"
		"vs_out.ID = ID;\n"
		"vs_out.Normal = Normal;\n"
		"}\n";


	const char* fShaderSource = "#version 450 core\n"
		"layout(location = 0) out vec4 color;\n"
		"in VS_OUT\n"
		"{\n"
		"vec2 TexCoord;\n"
		"uint ID;\n"
		"vec3 Normal;\n"
		"}ps_in;\n"
		"void main()\n"
		"{\n"
		"color = vec4(ps_in.Normal, 1.0f);\n"
		"}\n";


	glShaderSource(vShader, 1, &vShaderSource, nullptr);
	glShaderSource(fShader, 1, &fShaderSource, nullptr);

	glCompileShader(vShader);
	glCompileShader(fShader);

	glAttachShader(program, vShader);
	glAttachShader(program, fShader);

	glLinkProgram(program);
	glUseProgram(program);

	uint32_t m_Vao;
	glGenVertexArrays(1, &m_Vao);
	glBindVertexArray(m_Vao);
	
	uint32_t stride = sizeof(glm::vec3)  + sizeof(glm::vec2) + sizeof(uint32_t) + sizeof(glm::vec3);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3)));
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(glm::vec3) + sizeof(glm::vec2) + sizeof(uint32_t)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	// MAKE A GRID HERE
	uint32_t m_Rows = 10, m_Columns = 11, NumIndices, NumVertices;

	std::vector<uint32_t> m_VertexIndices;
	std::vector<glm::vec3> m_Positions;
	std::vector<glm::vec2> m_TexCoords;
	std::vector<uint32_t> m_VertexIDs;
	std::vector<glm::vec3> m_Normals;
	std::vector<Vertex> m_V;

	float x_offset = float(m_Columns) / 2;
	float y_offset = 0;
	float z_offset = 0;

	float z = 0;

	auto ConstructTriangles = [](std::vector<glm::vec3> pos, std::vector<glm::vec2> tex, std::vector<glm::vec3> norm, uint32_t index)
		{
			return Vertex{ pos[index], tex[index], index + 10, norm[index] };
		};

	for (int j = 0; j < m_Columns; j++)
	{
		for (int i = 0; i < m_Rows; i++)
		{
			uint32_t id = i + j * i;
			std::vector<Vertex> v1 = {
				{{i - x_offset, z + z_offset, j + y_offset}, {i / m_Columns, j / m_Rows}, id, {0.002f, 0.0f, 0.427f}},
				{{i + 1 - x_offset, z + z_offset, j + y_offset}, {(i + 1) / m_Columns, j / m_Rows}, id, {0.002f, 0.0f, 0.427f} },
				{{i + 1 - x_offset, z + z_offset, j + 1 + y_offset}, {(i + 1) / m_Columns, (j + 1) / m_Rows}, id,  {0.002f, 0.0f, 0.427f}},
				//{{i - x_offset, z + z_offset, j + 1 + y_offset}, {i / m_Columns, (j + 1) / m_Rows}, id, {0, 1,0}}
				{{i + 1 - x_offset, z + z_offset, j + 1 + y_offset}, {(i + 1) / m_Columns, (j + 1) / m_Rows}, id, {0.002f, 0.0f, 0.427f}}
			};
			std::vector<uint32_t> v_indices1 =
			{
				0, 1, 2, 3
			};
			for (auto& i : v_indices1) {
				m_VertexIndices.push_back(i);
			}
			for (auto& v : v1)
			{
				m_V.push_back(v);
				m_Positions.push_back(v.pos);
				m_TexCoords.push_back(v.tex);
				m_VertexIDs.push_back(v.ID);
				m_Normals.push_back(v.norm);
			}
		}

		NumIndices = m_VertexIndices.size();
		NumVertices = m_Positions.size();
	}

	glBufferSubData(GL_ARRAY_BUFFER, 0 * sizeof(Vertex) * NumIndices, sizeof(Vertex) * NumIndices, (void*)m_V.data());
	glBufferSubData(GL_ARRAY_BUFFER, 1 * sizeof(Vertex) * NumIndices, sizeof(Vertex) * m_sq[0].NumIndices, (void*)m_sq[0].m_V.data());

	int32_t vp_location, model_location, delta_location;

	vp_location = glGetUniformLocation(program, "VP");
	model_location = glGetUniformLocation(program, "Model");
	delta_location = glGetUniformLocation(program, "delta");

	while (true)
	{

		// BEGIN FRAME
		app.StartTimer();
		// DRAW
		//
		app.BeginFrame();

		//glClearColor(0.0F, 0.017, 0.43, 0.76);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(vp_location, 1, GL_FALSE, glm::value_ptr(app.GetVP()));
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
		glUniform1f(delta_location, app.ts);

		glDrawArrays(GL_LINE_STRIP, 0, NumIndices);

		for (int i=0;i<ARRAYSIZE(m_sq);i++)
		{

			glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(m_sq[i].m_Transform));
			glDrawArrays(GL_TRIANGLES, NumIndices, m_sq[i].m_V.size());
		}

		// END FRAME
		glFlush();
		GLbitfield flags = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
		glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, flags, GL_NEAREST);
		app.EndFrame();

		app.Run();
	}

	return 0;
}

void MyApplication::Run()
{
	m_Cam.Present();

	for (auto v : m_Window.m_SceneEventQueue.m_Queue)
	{
		MouseWheel* m = nullptr;
		int delta = 0;
		switch (v->m_ID)
		{
		case EventID::None:
			break;
			// MOUSE
		case EventID::L_MOUSEDOWN:
			break;
		case EventID::M_MOUSEDOWN:
			break;
		case EventID::R_MOUSEDOWN:
			break;

		case EventID::MOUSEWHEEL:

			m = reinterpret_cast<MouseWheel*>(v);
			delta = m->m_WheelDelta;
			if (delta > 0)
			{
				m_Cam.MoveForward();
			}
			else
			{
				m_Cam.MoveBackward();
			}
			break;
			// KEYBOARD
		case EventID::A:
			m_Cam.MoveLeft();
			break;
		case EventID::D:
			m_Cam.MoveRight();
			break;
		case EventID::Q:
			m_Cam.MoveForward();
			break;
		case EventID::S:
			m_Cam.MoveDown();
			break;
		case EventID::W:
			m_Cam.MoveUp();
			break;
		case EventID::Z:
			m_Cam.MoveBackward();
		}
		v->Resolve();
	}
	
	EndTimer();
	ts = (t_end - t_start);
	m_Cam.OnUpdate(10.0f);
	m_Window.OnUpdate();
	m_UILayer.OnUpdate(ts);
	m_Window.SwapBuffer();

}
