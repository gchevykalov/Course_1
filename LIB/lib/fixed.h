#ifndef FIXED_H_INCLUDED__
#define FIXED_H_INCLUDED__
#pragma once

/**
 * @mainpage General description

Fixed ������������ ����� ���������� ���������� ��� ������ � ������������� �������
� ������������� ������. ��� ��������� ��������� ���������� �������������� ��������
� ������� ����� ����, � ����� ��������������� ������������ ����� � �������������
������ � ������� ����� � �������.
 */

/**
 * @defgroup const_group Constant
 *
 * ���������, ��������������� �����������.
 *
 * @{
 */

/**
 * @brief ����.
 *
 * ���������, ������������ ������� �������� ���������� ���� "������������ �����
 * � ������������� ������".
 */
#define ZERO 0

/**@}*/

/**
 * @defgroup type_group Type
 *
 * ���� ������, ��������������� �����������.
 *
 * @{
 */

/**
 * @brief ��� - ������������ ����� � ������������� ������.
 *
 * ��� ������������� ������������ ����� � ������������� ������ �������� ������ ���.
 * � ������ ���������� �� ������� ����� ��������� 16 ���, ������� �� ��������� ��
 * ����� �����. ��������� ���� ���, �� 16 ��������������� ����� �����, ��������� �����,
 * �������� �������� ����� ������� ���� �� +-0.000015 �� +-32767.999985
 */
typedef struct {
  int f;
} fixed_t;

/**@}*/

/**
 * @defgroup conversion_group Type conversion
 *
 * ������� �������������� ������������ ����� � ������������� ������ � ������� ����� � �������.
 *
 * @{
 */

/**
 * @brief �������������� �� ������ �����.
 *
 * ����������� ����� ����� � ������������ ����� � ������������� ������.
 *
 * @param value - �������� ������ �����.
 *
 * @return ������������ ����� � ������������� ������, �������� �������� ����� value.
 */
fixed_t FixedFromInt(int value);

/**
 * @brief �������������� � ������ �����.
 *
 * ����������� ������������ ����� � ������������� ������ � ����� �����.
 *
 * @param value - �������� ������������� ����� � ������������� ������.
 *
 * @return ����� �����, �������� �������� ����� ����� ����� value.
 */
int FixedAsInt(fixed_t value);

/**
 * @brief �������������� �� ������������� ����� � ��������� ������.
 *
 * ����������� ������������ ����� � ��������� ������ � ������������ ����� � ������������� ������.
 * ���������� ������ ��������.
 *
 * @param value - �������� ������������� ����� � ��������� ������.
 *
 * @return ������������ ����� � ������������� ������, �������� �������� �������� ����� value.
 */
fixed_t  FixedFromDouble(double value);

/**
 * @brief �������������� � ������������� ����� � ��������� ������.
 *
 * ����������� ������������ ����� � ������������� ������ � ������������ ����� � ��������� ������.
 *
 * @param value - �������� ������������� ����� � ������������� ������.
 *
 * @return ������������ ����� � ��������� ������, �������� �������� ����� value.
 */
double FixedAsDouble(fixed_t value);

/**
 * @brief �������� ������������� ����� � ������������� ������ �� ������.
 *
 * ������������ ��������� ������������� ����� � ������������� ������, �����������
 * � ������ � ������� "Fix[...]". ����� ����� ������ ���������� ����������� ��������.
 *
 * @param str - ������, �� ������� ������������ ��������� ������������� ����� � ������������� ������.
 * @param end - ��������� �� ���������;
 * *end ����� ��������� ��������� �� ������, ��������� ����� �� ������������ ������ � ������������� ������.
 * *end ��������������� � NULL, ���� �� ������� �������� ������������ ����� � ������������� ������.
 *
 * @return �������� ������������� ����� � ������������� ������, ����������� �� ������.
 * ���������� ZERO � ������ �������.
 */
fixed_t FixedParse(char const* str, char const** end);

/**
 * @brief ������ ������������� ����� � ������������� ������ � ������.
 *
 * ������� ������, � ������� ���������� ������������ ����� � ������������� ������,
 * � ������� "Fix[...]".
 *
 * @param fixedValue - �������� ������������� ����� � ������������� ������.
 *
 * @return ��������� �� ������, � ������ �������� ������������ ����� � ������������ ������.
 * ���������� NULL � ������ �������.
 */
char* FixedFormat(fixed_t fixedValue);

/**@}*/

/**
 * @defgroup mathematical_group Mathematical operation
 *
 * ������� ��� ���������� �������������� �������� � ������������� ������� � ������������� ������.
 *
 * @{
 */

/**
 * @brief ����� ���� ������������ ����� � ������������� ������.
 *
 * @param value1 - ������ ���������.
 * @param value2 - ������ ���������.
 *
 * @return ����� �������� �����.
 */
fixed_t FixedAdd(fixed_t value1, fixed_t value2);

/**
 * @brief �������� ���� ������������ ����� � ������������� ������.
 *
 * @param value1 - �����������.
 * @param value2 - ����������.
 *
 * @return �������� �������� �����.
 */
fixed_t FixedSub(fixed_t value1, fixed_t value2);

/**
 * @brief ������������ ���� ������������ ����� � ������������� ������.
 *
 * @param value1 - ������ ���������.
 * @param value2 - ������ ���������.
 *
 * @return ������������ �������� �����. ��� ������ �� ������� fixed_t ���������� -32768.
 */
fixed_t FixedMul(fixed_t value1, fixed_t value2);

/**
 * @brief ������� ���� ������������ ����� � ������������� ������.
 *
 * @param value1 - �������.
 * @param value2 - ��������.
 *
 * @return ������� �������� �����. ��� ������ �� ������� fixed_t ���������� -32768.
 */
fixed_t FixedDiv(fixed_t value1, fixed_t value2);

/**
 * @brief ��������������� ����� ������������� ����� � ������������� ������.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return ����� ��������������� ���������.
 */
fixed_t FixedNegate(fixed_t value);

/**
 * @brief �������� ����� ������������� ����� � ������������� ������.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return ����� �������� ���������. ��� ������ �� ������� fixed_t ���������� -32768.
 */
fixed_t FixedReciprocal(fixed_t value);

/**
 * @brief ���������� �������� ������������� ����� � ������������� ������.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return ���������� �������� ������������� ����� � ������������� ������.
 */
fixed_t FixedAbs(fixed_t value);

/**
 * @brief ���������� ����.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return �������� ������������ ���� ������������� ����� � ������������� ������.
 */
fixed_t FixedFloor(fixed_t value);

/**
 * @brief ���������� �����.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return �������� ������������ ����� ������������� ����� � ������������� ������.
 */
fixed_t FixedCeil(fixed_t value);

/**
 * @brief �������������� ����������.
 *
 * @param value - ������������ ����� � ������������� ������.
 *
 * @return �������� ������������ �� ��������������� ������� ������������� ����� � ������������� ������.
 */
fixed_t FixedRound(fixed_t value);

/**
 * @brief ��������� ���� ������������ ����� � ������������� ������.
 *
 * @param value1 - ��������� �� ������������ ����� � ������������� ������.
 * @param value2 - ��������� �� ������������ ����� � ������������� ������.
 *
 * @return -1, ���� ������ ����� ������;
 * 0, ���� ����� �����;
 * 1, ���� ������ ����� ������.
 */
int FixedCompare(fixed_t const* value1, fixed_t const* value2);

/**@}*/

/**
 * @defgroup stream_group Stream functions
 *
 * ������� ��� �������� ������������� ����� � ������������� ������ �� ������
 * � ������ ������������� ����� � ������������� ������ � ����� � ��������� ����,
 * � ������� "Fix[...]".
 *
 * @{
 */

/**
 * @brief �������� ������������� ����� � ������������� ������ �� ������.
 *
 * ��������� ������ �������� �� ����������� �������(������ ������� ���������� ������� ������������) �
 * �������� �� ��� ������������ ����� � ������������� ������, ���������� � ���� "Fix[...]".
 * ����������� ���������� �������� *value.
 *
 * @param value - ��������� �� ������������ ����� � ������������� ������.
 * @param stream - ��������� �� �����, �� �������� ��������� ������������ ����� � ������������� ������.
 *
 * @return 1, � ������ ������;
 * 0, � ������ �������.
 */
int FixedRead(fixed_t* value, FILE* stream);

/**
 * @brief ���������� ������������ ����� � ������������� ������ � �����.
 *
 * ���������� ������������ ����� � ������������� ������ � �����, � ������� "Fix[...]".
 *
 * @param value - ������������ ����� � ������������� ������.
 * @param stream - ��������� �� �����, � ������� ��������� ������������ ����� � ������������� ������.
 *
 * @return 1, � ������ ������;
 * 0, � ������ �������.
 */
int FixedWrite(fixed_t value, FILE* stream);

/**@}*/
#endif