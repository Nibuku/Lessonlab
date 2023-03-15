#include <gtest/gtest.h>

#include <lesson/lesson.h>
#define CAPACITY 10
using namespace lesson;
using namespace std;
TEST(LessonTests, LabTest1) {
    // Arrange
    Lesson lesson(LessonType::LAB, Name::OOP, 5);
    
    // Act
    int r = lesson.compute_paid_hours(4, 8);
    
    // Assert
    EXPECT_EQ(r, 40);
}


TEST(LessonTests, LectureTest1) {
    // Arrange
    Lesson lesson(LessonType::LECTURE, Name::OOP, 5);

    // Act
    int r = lesson.compute_paid_hours(4, 8);

    // Assert
    EXPECT_EQ(r, 5);
}

TEST(LessonTests, PracticeTest1) {
    // Arrange
    Lesson lesson(LessonType::PRACTICE, Name::OOP, 5);

    // Act
    int r = lesson.compute_paid_hours(4, 8);

    // Assert
    EXPECT_EQ(r, 20);
}

TEST(LessonTests, ForGetName) {
    // Arrange
    Lesson lesson(LessonType::PRACTICE, Name::OOP, 5);

    // Act
    int r = lesson.getName();

    // Assert
    EXPECT_EQ(r, OOP);
}
TEST(LessonTests, ForGetHours) {
    // Arrange
    Lesson lesson(PRACTICE, Name::ALGEBRA, 5);

    // Act
    int r = lesson.gethours();

    // Assert
    EXPECT_EQ(r, 5);
}
TEST(LessonTests, ForGetType) {
    // Arrange
    Lesson lesson(PRACTICE, Name::ALGEBRA, 5);

    // Act
    int r = lesson.getLessonType();

    // Assert
    EXPECT_EQ(r, PRACTICE);
}
TEST(LessonTests, GetType) {
    // Arrange
    Lesson lesson(LAB, Name::ALGEBRA, 5);

    // Act
    int r = lesson.getLessonType();

    // Assert
    EXPECT_EQ(r, LAB);
}
TEST(LessonTests, SetType) {
    // Arrange
    Lesson lesson;

    // Act
     lesson.setLessonType(PRACTICE);

    // Assert
    EXPECT_EQ(lesson.getLessonType(), PRACTICE);
}
TEST(LessonTests, SetName) {
    // Arrange
    Lesson lesson;

    // Act
    lesson.setName(OOP);

    // Assert
    EXPECT_EQ(lesson.getName(), OOP);
}
TEST(LessonTests, Sethours) {
    // Arrange
    Lesson lesson;

    // Act
    lesson.sethours(12);

    // Assert
    EXPECT_EQ(lesson.gethours(), 12);
}
TEST(LessonTests, Compute1Sum) {
    // Arrange
    LessonList lesson= LessonList();

    // Act

    // Assert
    EXPECT_EQ(lesson.compute_sum(lesson, 4, 8, OOP),0 );
}

TEST(LessonTests, ComputeSum) {
    // Arrange
   const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LAB, OOP, 8);
    LessonList ll=LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.compute_sum(ll, 4, 8, OOP), 128);
}
TEST(LessonTests, ComputeSum2) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LAB, OOP, 8);
    lesson[2] = Lesson(PRACTICE, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.compute_sum(ll, 4, 8, ALGEBRA), 32);
}
TEST(LessonTests, ComputeSum3) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LECTURE, OOP, 8);
    lesson[2] = Lesson(PRACTICE, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.compute_sum(ll, 4, 8, OOP), 72);
}

TEST(LessonTests, ComputeMax) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LAB, OOP, 8);
    lesson[2] = Lesson(LAB, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.compute_max_paid(ll, 4, 8), OOP);
}
TEST(LessonTests, ComputeMax2) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(PRACTICE, OOP, 8);
    lesson[2] = Lesson(LAB, ALGEBRA, 8);
    lesson[3] = Lesson(LAB, GEOMETRIYA, 8);
    lesson[4] = Lesson(LECTURE, GEOMETRIYA, 8);
    LessonList ll = LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.compute_max_paid(ll, 4, 8), OOP);
}
TEST(LessonTests, Size ) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LAB, OOP, 8);
    lesson[2] = Lesson(LAB, ALGEBRA, 8);
    lesson[3] = Lesson(LAB, ALGEBRA, 8);
    lesson[4] = Lesson(LAB, ALGEBRA, 8);
    lesson[5] = Lesson(LAB, ALGEBRA, 8);
    lesson[6] = Lesson(LAB, ALGEBRA, 8);
    lesson[7] = Lesson(LAB, ALGEBRA, 8);
    lesson[8] = Lesson(LAB, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);

    // Assert
    EXPECT_EQ(ll.size(), 5);
}
TEST(LessonTests, Remove) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LECTURE, OOP, 8);
    lesson[2] = Lesson(PRACTICE, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);
    ll.remove(2);

    // Assert
    EXPECT_EQ(ll.compute_sum(ll, 4, 8, ALGEBRA), 0);
}
TEST(LessonTests, Insert) {
    // Arrange
    const int size = 5;
    Lesson lesson[CAPACITY];
    lesson[0] = Lesson(LAB, OOP, 8);
    lesson[1] = Lesson(LECTURE, OOP, 8);
    lesson[2] = Lesson(PRACTICE, ALGEBRA, 8);
    LessonList ll = LessonList(lesson, size);
    ll.insert(2, Lesson( LAB, OOP, 2));

    // Assert
    EXPECT_EQ(ll.compute_sum(ll, 4, 8, OOP), 88);
}
TEST(LessonTests, Index) {
    LessonList ll = LessonList();
    EXPECT_THROW(ll.remove(-1), std::runtime_error);
}

