#ifndef TypeActors_h__
#define TypeActors_h__

namespace GameActors
{

	enum TypeActor 
	{
		TA_Computer,
		TA_User,
		TA_RemoteUser,
		TA_Unknoun
	};

	static const char* NamesTypeActor []  = 
	{
		"Computer",
		"User",
		"Remote User",
		"no one's"
	};

}

#endif // TypeActors_h__