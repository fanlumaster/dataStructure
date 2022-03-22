#define NotFound 0 /* 找不到则返回0 */

Position BinarySearch( List Tbl, ElementType K )
{ /* 在顺序存储的表Tbl中查找关键字为K的数据元素 */
	Position left, right, mid;

    left = 1;          /* 初始左边界 */
    right = Tbl->Last; /* 初始右边界 */
    while( left<=right )
    {
        mid = (left+right)/2;  /* 计算中间元素坐标 */
        if( K<Tbl->Data[mid] )      right = mid - 1; /* 调整右边界 */
        else if( K>Tbl->Data[mid] ) left = mid + 1;  /* 调整左边界 */
        else return mid;   /* 查找成功，返回数据元素的下标 */
    }
    return NotFound;   /* 返回查找不成功的标识 */
}
