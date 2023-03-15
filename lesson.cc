#include <lesson/lesson.h>
#include <stdexcept>
using namespace lesson;
using namespace std;
Lesson::Lesson(LessonType type,Name name, int hours)
{
	this->_type = type;
	this->_hours = hours;
	this->_name = name;
}

Lesson::Lesson() {
	_type = LAB;
	_name = OOP;
	_hours = 0;
}

int Lesson::compute_paid_hours(int groups, int subgroups)
{
	switch(_type)
	{
	case LECTURE:
		return _hours;
	case LAB:
		return subgroups * _hours;
	case PRACTICE:
		return groups * _hours;
	default:
		throw runtime_error("error2");
	}
}

int LessonList::compute_sum( LessonList& t, int groups, int subgroups, Name name) const{
	const int n = t.size();
	int s = 0;
	for (int i = 0; i < n; ++i) {
		if (name == t[i].getName()) {
			s = s + t[i].compute_paid_hours(groups, subgroups);

		}
	}
	return s;
}

Name LessonList::compute_max_paid(LessonList& t, int groups, int subgroups) {
	const int n = t.size();
	int max = 0;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (max < t[i].compute_paid_hours(groups, subgroups)) {
			max = t[i].compute_paid_hours(groups, subgroups);
			index = i;
		}
	}
	return t[index].getName();
}

int LessonList::size() const {
	return _size;
}

LessonType Lesson::getLessonType() {
	return _type;
}

int Lesson::gethours() {
	return _hours;
}

Name Lesson::getName() {
	return _name;
}

void Lesson::sethours(int _hours) {
	this->_hours = _hours;
}

void Lesson::setLessonType(LessonType _type) {
	this->_type = _type;
}

void Lesson::setName(Name _name) {
	this->_name = _name;
}

LessonList::LessonList() 
{ this->_size = 9;
for (int i = 0; i < 9; i++) {
	this->_lesson[i] = Lesson();
	}
}

LessonList::LessonList(Lesson _lesson[], int _size) { 
	this->_size = _size;
	for (int i = 0; i <= _size; i++) {
	this->_lesson[i].setName(_lesson[i].getName());
	this->_lesson[i].setLessonType(_lesson[i].getLessonType());
	this->_lesson[i].sethours(_lesson[i].gethours());
	}

}

void LessonList::insert(int index, Lesson f) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	for (int i=_size-1; i>=index; --i) {
		_lesson[i] = _lesson[i - 1];
		
	} ++_size;
	_lesson[index] = f;
}

void LessonList::remove(int index) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	for (int i = index; i < _size - 1; ++i) {
		_lesson[i] = _lesson[i + 1];
	}  --_size;
}

Lesson& LessonList::operator[]( int index) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	return _lesson[index];
}