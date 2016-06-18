#ifndef HGEApplication_h__
#define HGEApplication_h__

namespace Application
{

	class HGEApplicationImpl;

	class HGEApplication
	{

		static HGEApplicationImpl hgeApplicationImpl;

	public:

		HGEApplication ();

		void Execute();

		~HGEApplication();

	private:

		HGEApplication ( const HGEApplication& );
		HGEApplication& operator= ( const HGEApplication& );

	private:

		static bool FrameFunc();
		static bool RenderFunc ();
	};

}

#endif // HGEApplication_h__