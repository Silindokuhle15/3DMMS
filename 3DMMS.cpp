#include "3DMMS.h"

std::vector<std::string> m_DemoPoses{
	//"C:/dev/Recon/NeutralPose/NeutralPoseFrameTwo.csv",
	//"C:/dev/Recon/NeutralPose/NeutralPoseFrameTHREE.csv",
	//"C:/dev/Recon/NeutralPose/NeutralPoseFrameFOUR.csv",
	"C:/dev/Recon/NeutralPose/NeutralPoseFrameFIVE.csv",
	//"C:/dev/Recon/NeutralPose/NeutralPoseFrameSIX.csv",
};

std::vector<std::string> m_pathToSBAComputerLabelledFiles
{
	"C:/dev/Recon/SBA_3d_points/Cam1_and_Cam2/SBA_Computer_labelled_frame1.csv",
	//"C:/dev/Recon/SBA_3d_points/Cam1_and_Cam2/SBA_Computer_labelled_frame2.csv",
	//"C:/dev/Recon/SBA_3d_points/Cam1_and_Cam2/SBA_Computer_labelled_frame3.csv",
	//"C:/dev/Recon/SBA_3d_points/Cam1_and_Cam2/SBA_Computer_labelled_frame4.csv",
	//"C:/dev/Recon/SBA_3d_points/Cam1_and_Cam2/SBA_Computer_labelled_frame25.csv",
};
std::vector<std::string> m_pathToSBAHumanLabelledFiles
{
	//"C:/dev/Recon/SBA_Human_labelled_3d_points/Cam1_and_Cam2/SBA_Human_labelled_frame1.csv",
	"C:/dev/Recon/SBA_Human_labelled_3d_points/Cam1_and_Cam2/SBA_Human_labelled_frame25.csv",
};	

std::vector<std::string> m_pathToConstrainedFiles
{
	/*
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_1.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_2.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_3.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_4.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_5.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_6.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_7.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_8.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_9.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_10.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_11.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_12.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_13.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_14.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_15.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_16.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_17.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_18.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_19.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_20.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_21.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_22.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_23.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_24.csv",
	*/
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_25.csv",
	/*
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_26.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_27.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_28.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_29.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_30.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_31.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_32.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_33.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_34.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_35.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_36.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_37.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_38.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_39.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_40.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_41.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_42.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_43.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_44.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_45.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_46.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_47.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_48.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_49.csv",
	"C:/dev/Recon/GeometricConstrained/refined_3d_points_frame_50.csv",
	*/
};

std::vector<std::string> m_pathToHumanLabelledFiles
{
	
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_1.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_2.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_3.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_4.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_5.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_6.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_7.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_8.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_9.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_10.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_11.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_12.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_13.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_14.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_15.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_16.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_17.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_18.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_19.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_20.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_21.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_22.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_23.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_24.csv",
	
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_25.csv",
	
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_26.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_27.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_28.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_29.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_30.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_31.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_32.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_33.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_34.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_35.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_36.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_37.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_38.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_39.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_40.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_41.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_42.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_43.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_44.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_45.csv",
	"C:/dev/Recon/3d_points/cam1_and_cam2/3d_points_frame_46.csv",
	
};

std::vector<std::string> m_pathToComputerLabelledFiles
{
	/*
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_1.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_2.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_3.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_4.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_5.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_6.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_7.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_8.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_9.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_10.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_11.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_12.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_13.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_14.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_15.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_16.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_17.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_18.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_19.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_20.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_21.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_22.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_23.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_24.csv",
	*/
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_25.csv",
	/*
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_26.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_27.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_28.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_29.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_30.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_31.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_32.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_33.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_34.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_35.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_36.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_37.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_38.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_39.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_40.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_41.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_42.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_43.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_44.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_45.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_46.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_47.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_48.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_50.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_51.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_52.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_53.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_54.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_55.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_56.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_57.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_58.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_59.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_60.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_61.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_62.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_63.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_64.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_65.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_66.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_67.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_68.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_69.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_70.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_71.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_72.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_73.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_74.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_75.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_76.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_78.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_79.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_80.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_81.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_82.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_83.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_84.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_85.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_86.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_87.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_88.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_89.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_90.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_91.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_92.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_93.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_94.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_95.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_96.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_97.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_98.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_99.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_100.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_101.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_102.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_103.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_104.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_105.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_106.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_107.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_108.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_109.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_110.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_111.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_112.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_113.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_114.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_115.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_116.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_117.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_118.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_119.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_120.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_121.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_122.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_123.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_124.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_125.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_126.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_127.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_128.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_129.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_130.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_131.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_132.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_133.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_134.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_135.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_136.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_137.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_138.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_139.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_140.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_141.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_142.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_143.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_144.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_145.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_146.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_147.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_148.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_150.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_151.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_152.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_153.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_154.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_155.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_156.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_157.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_158.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_159.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_160.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_161.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_162.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_163.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_164.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_165.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_166.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_167.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_168.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_169.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_170.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_171.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_172.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_173.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_174.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_175.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_176.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_177.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_178.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_179.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_180.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_181.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_182.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_183.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_184.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_185.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_186.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_187.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_188.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_189.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_190.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_191.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_192.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_193.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_194.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_195.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_196.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_197.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_198.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_199.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_200.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_201.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_202.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_203.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_204.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_205.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_206.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_207.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_208.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_209.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_210.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_211.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_212.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_213.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_214.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_215.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_216.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_217.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_218.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_219.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_220.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_221.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_222.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_223.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_224.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_225.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_226.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_227.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_228.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_229.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_230.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_231.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_232.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_233.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_234.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_235.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_236.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_237.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_238.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_239.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_240.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_241.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_242.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_243.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_244.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_245.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_246.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_247.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_248.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_250.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_251.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_252.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_253.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_254.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_255.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_256.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_257.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_258.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_259.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_260.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_261.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_262.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_263.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_264.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_265.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_266.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_267.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_268.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_269.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_270.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_271.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_272.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_273.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_274.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_275.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_276.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_277.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_278.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_279.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_280.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_281.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_282.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_283.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_284.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_285.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_286.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_287.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_288.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_289.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_290.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_291.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_292.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_293.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_294.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_295.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_296.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_297.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_298.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_299.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_200.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_301.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_302.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_303.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_304.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_305.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_306.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_307.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_308.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_309.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_310.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_311.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_312.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_313.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_314.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_315.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_316.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_317.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_318.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_319.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_320.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_321.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_322.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_323.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_324.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_325.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_326.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_327.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_328.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_329.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_330.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_331.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_332.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_333.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_334.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_335.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_336.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_337.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_338.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_339.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_340.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_341.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_342.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_343.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_344.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_345.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_346.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_347.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_348.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_350.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_351.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_352.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_353.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_354.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_355.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_356.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_357.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_358.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_359.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_360.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_361.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_362.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_363.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_364.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_365.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_366.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_367.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_368.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_369.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_370.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_371.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_372.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_373.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_374.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_375.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_376.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_377.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_378.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_379.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_380.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_381.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_382.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_383.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_384.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_385.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_386.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_387.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_388.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_389.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_390.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_391.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_392.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_393.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_394.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_395.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_396.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_397.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_398.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_399.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_300.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_401.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_402.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_403.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_404.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_405.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_406.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_407.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_408.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_409.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_410.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_411.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_412.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_413.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_414.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_415.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_416.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_417.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_418.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_419.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_420.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_421.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_422.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_423.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_424.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_425.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_426.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_427.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_428.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_429.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_430.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_431.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_432.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_433.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_434.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_435.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_436.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_437.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_438.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_439.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_440.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_441.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_442.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_443.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_444.csv",
	"C:/dev/Recon/Computer_labelled_3d_points/Cam1_and_Cam2/3d_points_frame_445.csv"
	*/
};



#define _MK_QUAT_FRM_VEC(q, v){                                     \
  (q)[1]=(v)[0]; (q)[2]=(v)[1]; (q)[3]=(v)[2];                      \
  (q)[0]=sqrt(1.0 - (q)[1]*(q)[1] - (q)[2]*(q)[2]- (q)[3]*(q)[3]);  \
}

void quat2vec(double* inp, int nin, double* outp, int nout)
{
	double mag, sg;
	register int i;

	/* intrinsics & distortion */
	if (nin > 7) // are they present?
		for (i = 0; i < nin - 7; ++i)
			outp[i] = inp[i];
	else
		i = 0;

	/* rotation */
	/* normalize and ensure that the quaternion's scalar component is non-negative;
	 * if not, negate the quaternion since two quaternions q and -q represent the
	 * same rotation
	 */
	mag = sqrt(inp[i] * inp[i] + inp[i + 1] * inp[i + 1] + inp[i + 2] * inp[i + 2] + inp[i + 3] * inp[i + 3]);
	sg = (inp[i] >= 0.0) ? 1.0 : -1.0;
	mag = sg / mag;
	outp[i] = inp[i + 1] * mag;
	outp[i + 1] = inp[i + 2] * mag;
	outp[i + 2] = inp[i + 3] * mag;
	i += 3;

	/* translation*/
	for (; i < nout; ++i)
		outp[i] = inp[i + 1];
}

void vec2quat(double* inp, int nin, double* outp, int nout)
{
	double* v, q[FULLQUATSZ];
	register int i;

	/* intrinsics & distortion */
	if (nin > 7 - 1) // are they present?
		for (i = 0; i < nin - (7 - 1); ++i)
			outp[i] = inp[i];
	else
		i = 0;

	/* rotation */
	/* recover the quaternion from the vector */
	v = inp + i;
	_MK_QUAT_FRM_VEC(q, v);
	outp[i] = q[0];
	outp[i + 1] = q[1];
	outp[i + 2] = q[2];
	outp[i + 3] = q[3];
	i += FULLQUATSZ;

	/* translation */
	for (; i < nout; ++i)
		outp[i] = inp[i - 1];
}


int testmain()
{
    int cnp = 6, /* 3 rot params + 3 trans params */
        pnp = 3, /* euclidean 3D points */
        mnp = 2; /* image points are 2D */

    const char* camin = "C:/dev/3DMMS/SBA/sba-1.6/demo/7cams.txt";
    const char* pin = "C:/dev/3DMMS/SBA/sba - 1.6 /demo/7pts.txt";
    const char* kin = "C:/dev/3DMMS/SBA/sba-1.6/demo/7camvarsK.txt";

    char* cc = const_cast<char*>(camin);
    char* cp = const_cast<char*>(pin);
    char* ck = const_cast<char*>(pin);


    //sba_driver(cc, cp, ck, cnp, pnp, mnp, quat2vec, vec2quat, cnp + 1, const_cast<char*>("-"), const_cast<char*>("-"));
    return 0;
}


int main(int argc, char* argv[])
{
	int width = 1920, height = 1080;
	MyApplication  app(width, height, "3DMMS");

	DoSomeThing();
	//QuadrupedDynamics geo_optim(m_pathToSBAComputerLabelledFiles);
	//QuadrupedDynamics geo_optim(m_pathToSBAHumanLabelledFiles);
	//QuadrupedDynamics geo_optim(m_pathToComputerLabelledFiles);
	//QuadrupedDynamics geo_optim(m_pathToHumanLabelledFiles);
	QuadrupedDynamics geo_optim(m_DemoPoses);
	//QuadrupedDynamics geo_optim;
	
	Mesh m_sq[] = {
		Mesh("C:/dev/3DMMS/Cube/Camera View Port.obj"),
		geo_optim.GetCurrentFrame()
		//Mesh(f1.m_mesh_cam1_and2_frame3),
		//Mesh(f1.m_mesh_cam1_and2_frame4),
		//Mesh(f1.m_mesh_cam1_and2_frame5)
		//Mesh("C:/dev/3DMMS/Sphere/Sphere.obj"),

		//Mesh("C:/dev/3DMMS/Cube/Cube.obj")
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj"),
		//Mesh("C:/dev/3DMMS/Cube/Cube.obj")
	};

	glm::mat4 camera_transforms[] =
	{
		//glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(0.3, 0.3, 0.3)), glm::vec3(-3,5, -5)),
		//glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(0.3, 0.3, 0.3)), glm::vec3(0,5, -5)),
		//glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(0.3, 0.3, 0.3)), glm::vec3(+3,5, -5)),
		glm::mat4(1.0f),
		//{
			//-0.294760955120045,		-0.495185364159318,	0.817256039720186, -0.589018328564083,
			//-0.0191541342820852,	0.858144053968970,	0.513051558595825,	-0.386807158869854,
			//-0.955379033931886,		0.135573735509887, -0.262432207938112,	0.285568024827855,
			//0,	0,	0,	1
		//}
	};
	for (int i = 0; i < ARRAYSIZE(m_sq); i++)
	{
		float sc = 0.5f, alpha = 1.5f;
		float xm = ARRAYSIZE(m_sq) / 2;
		//m_sq[i].m_Transform = glm::scale(glm::mat4(1.0f), glm::vec3(sc, sc, sc));
		//m_sq[i].m_Transform = glm::rotate(m_sq[i].m_Transform, glm::radians(90.0f), glm::vec3(0, 0, 1));
		//m_sq[i].m_Transform = glm::rotate(m_sq[i].m_Transform, glm::radians(90.0f), glm::vec3(0, 1, 0));
		//m_sq[i].m_Transform = glm::translate(m_sq[i].m_Transform, glm::vec3((i-xm)*(1+alpha), 0.0f, ARRAYSIZE(m_sq)));
		//m_sq[i].m_Transform = glm::translate(transforms[i], glm::vec3(0.0, 0.0, 0.90f));
		m_sq[i].OnInit();
	}



	uint32_t MAX_NUM_VERTICES = 100000;
	//glDisable(GL_CULL_FACE);

	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_LINE_WIDTH);
	glEnable(GL_LINE_SMOOTH);

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
		"gl_PointSize = 2;"
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
	uint32_t m_Rows = 20, m_Columns = 21, NumIndices, NumVertices;

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
	uint32_t offset = sizeof(Vertex) * NumIndices;
	
	int32_t vp_location, model_location, delta_location;

	vp_location = glGetUniformLocation(program, "VP");
	model_location = glGetUniformLocation(program, "Model");
	delta_location = glGetUniformLocation(program, "delta");
	
	//testmain();

	while (true)
	{
		GLbitfield flags = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
		// BEGIN FRAME
		app.StartTimer();
		
		// DRAW
		//
		app.BeginFrame();

		//glClearColor(0.0F, 0.017, 0.43, 0.76);
		glClear(flags);

		glUniformMatrix4fv(vp_location, 1, GL_FALSE, glm::value_ptr(app.GetVP()));
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
		glUniform1f(delta_location, app.ts);

		glLineWidth(3.0f);
		//glDrawArrays(GL_LINE_STRIP, 0, NumIndices);

		// DRAW THE CAMERA VIEWPORTS
		
		glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(Vertex) * m_sq[0].m_V.size(), (void*)m_sq[0].m_V.data());
		uint32_t cam_index = 0;
		for (cam_index = 0; cam_index < ARRAYSIZE(camera_transforms); cam_index++)
		{
			glLineWidth(1.0f);
			glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(camera_transforms[cam_index]));
			glDrawArrays(GL_LINE_STRIP, NumIndices , m_sq[0].m_V.size());
		}
		
	
		
		//auto data = dog1.GetCurrentFrame();
		auto data = geo_optim.GetCurrentFrame();

		for (int timing_index = 0; timing_index < 10000000; timing_index++)
		{

		}
		//offset += sizeof(Vertex) * m_sq[0].m_V.size();
		glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(Vertex) * data.m_V.size(), (void*)data.m_V.data());

		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, 7.50f))));
		//glPointParameterf(GL_POINT_SIZE, 50);
		//NumIndices += m_sq[0].m_V.size();
		//glDrawArrays(GL_POINTS, NumIndices, m_sq[1].m_V.size());

		//dog1.AdvanceFrame();
		geo_optim.AdvanceFrame();
		// Draw the lines
		glLineWidth(5.0f);
		glDrawArrays(GL_LINE_STRIP, NumIndices, 4); // Draw a line from head to throat_base
		glDrawArrays(GL_LINE_STRIP, NumIndices + 4, 4); // Draw a line from back_base to front_left_thai to front_left_knee to front_left_paw
		glDrawArrays(GL_LINE_STRIP, NumIndices + 8, 4); // Draw a line from back_base to front_right_thai to front_right_knee to front_right_paw
		
		glDrawArrays(GL_LINE_STRIP, NumIndices + 11, 2); // Draw a line from back_base to torso to tail_base
		glDrawArrays(GL_LINE_STRIP, NumIndices + 13, 4); // Draw a line from tail_base to back_left_thai to back_left_knee to back_left_paw
		glDrawArrays(GL_LINE_STRIP, NumIndices + 17, 4); // Draw a line from tail_base to back_right_thai to back_right_knee to back_right_paw
		glDrawArrays(GL_LINE_STRIP, NumIndices + 20, 2); // Draw a line from tail_base to tail_end

		glDisable(GL_LINE_WIDTH);

		//glDrawArrays(GL_LINES, NumIndices, data.m_V.size());
		//glDrawArrays(GL_POINT, NumIndices + 0, 2);

		//glDrawArrays(GL_LINES, NumIndices + 1, 2); //upper_jaw - lower_jaw
		//glDrawArrays(GL_LINES, NumIndices + 3, 2); // mouth_end_right - lower_jaw
		//glDrawArrays(GL_LINES, NumIndices + 5, 2); // mouth_end_left - lower_jaw

		//glDrawArrays(GL_LINE_STRIP, NumIndices + 7, 3); // right_eye - right_earend
		//glDrawArrays(GL_LINE, NumIndices + 10, 2); // right_antlerbase - right_antler_end

		//glDrawArrays(GL_LINE_STRIP, NumIndices + 12, 3); // left_eye - left_earnd
		//glDrawArrays(GL_LINE, NumIndices + 15, 2); // left_antlerbase - left_antler_end

		//glDrawArrays(GL_LINE_STRIP, NumIndices + 17, 9); // neck_base - tail_end

		//glDrawArrays(GL_LINE_STRIP, NumIndices + 26, 4); // back_base - front_left_paw
		//glDrawArrays(GL_LINE_STRIP, NumIndices + 30, 4); // back_base - front_right_paw

		//glDrawArrays(GL_LINES, NumIndices + 31, 2);
		//glDrawArrays(GL_LINES, NumIndices + 33, 2);

		//glDrawArrays(GL_LINE_STRIP, NumIndices + 35, 4); // tail_base - back_right_paw
		//glDrawArrays(GL_LINE_STRIP, NumIndices + 39, 4); // tail_base - back_left_paw

		//glDrawArrays(GL_LINES, NumIndices + 42, 5);

		// END FRAME
		glDrawBuffer(GL_COLOR_ATTACHMENT0);
		glFlush();

		glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, flags, GL_NEAREST);
		app.EndFrame();

		app.Run();
	}

	return 0;
}

void MyApplication::Run()
{
	//DoSomeThing();

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
	//ts = m_Window.ts * 0.1f/60.0f;
	// To Do : More Research on why updating based on a variable timestep causes flickering
	ts = 10.0f/60.0f;
	m_Cam.OnUpdate(ts);
	m_Window.OnUpdate();
	m_UILayer.OnUpdate(ts);
}

void Quadruped::AdvanceFrame()
{
	//m_Frames.shrink_to_fit();
	if (m_CurrentFrame < m_NumberofFrames - 1)
	{
		m_CurrentFrame++;
	}
	else
	{
		m_CurrentFrame = 0;
	}
}

void Quadruped::LoadFramesFromeCSV(std::string csv_filepath)
{
	io::CSVReader<3> cam1_reader(csv_filepath.c_str());
	//io::CSVReader<3> cam2_reader(path_to_files[1]);

	//cam1_reader.read_header(io::ignore_missing_column, "A", "B", "C");

	mycsvfields  csv_field;
	auto readCSVFunc = [](io::CSVReader<3>& reader, mycsvfields& view)
		{
			return reader.read_row(view.x, view.y, view.z);
		};

	std::vector<Vertex> vertex_data;

	while (readCSVFunc(cam1_reader, csv_field))
	{
		// CHECK FOR EMPTY FIELD
		double x, y, z;
		x = std::atof(csv_field.x.c_str());
		y = std::atof(csv_field.y.c_str());
		z = std::atof(csv_field.z.c_str());
		//m_Frames[m_CurrentFrame].push_back(Vertex{glm::vec3(x, y,z),{0.0, 0.0}, {1},{0.0, 1.0, 0.0}});
		vertex_data.push_back(Vertex{ glm::vec3(x, y,z),{0.0, 0.0}, {1},{0.0, 1.0, 0.0} });
	}
	m_Frames.push_back(Mesh(vertex_data));
	m_NumberofFrames++;
}
