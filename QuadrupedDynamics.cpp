#include "QuadrupedDynamics.h"

void QuadrupedDynamics::AdvanceFrame()
{
	if (m_CurrentFrame < m_NumberofFrames - 1)
	{
		m_CurrentFrame++;
	}
	else
	{
		m_CurrentFrame = 0;
	}
}
