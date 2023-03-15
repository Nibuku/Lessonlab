#pragma once
#include <string>
using namespace std;
namespace lesson
{

	enum LessonType
	{
		LECTURE,
		LAB,
		PRACTICE
	};

	enum Name
	{
		OOP,
		ALGEBRA,
		GEOMETRIYA,
		DISKRETNAYA_MATEMATIKA
	};


	class Lesson {
	private:
		LessonType _type;
		Name _name;
		int _hours;
	public:
		Lesson();
		Lesson(LessonType type, Name name, int hours);
		int compute_paid_hours(int groups, int subgroups);
		Name getName();
		LessonType getLessonType();
		int gethours();
		void setName(Name _name);
		void setLessonType(LessonType _type);
		void sethours(int _hours);

	};

	class LessonList {
	public:
		static const int CAPACITY = 10;
	private:
		Lesson _lesson[CAPACITY];
		int _size ;

	public:
		LessonList();
		LessonList(Lesson _lesson[], int _size);
		int size() const;
		void insert(int index, Lesson f);
		void remove(int index);
		Lesson& operator[](int index) ;
		int compute_sum( LessonList& t, int groups, int subgroups, Name name) const;
		Name compute_max_paid( LessonList& t, int groups, int subgroups);
	};
	
}