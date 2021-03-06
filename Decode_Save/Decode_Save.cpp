/************************************************************************
 *	Filename:		XXXXX
 *	Copyright:		XXXXX Company Software Co., Ltd.
 *
 *	Description:	$(Desp) .
 *
 *	@author:		XXXXX
 *	@version		DATE	AUTHOR	Initial Version
*************************************************************************/
#include "cvdrivercommon.h"

/**
*  获取驱动版本号.
*
*  @version   07/20/2012   Initial Version.
*/
CVDRIVER_EXPORTS long GetDrvFrameVersion()
{
	return 2;
}

/**
 *  初始化函数，驱动EXE启动时该函数被调用，可在该函数中实现自定义初始化操作.
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012    Initial Version.
 */
CVDRIVER_EXPORTS long Initialize()
{
	//TODO：初始化操作
	
	return DRV_SUCCESS;
}

/**
 *  驱动EXE退出时该函数被调用.
 *  在该函数中可以释放自定义资源、断开设备连接等操作.
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012    Initial Version.
 */
CVDRIVER_EXPORTS long UnInitialize()
{
	//TODO：退出清理操作
	
	return DRV_SUCCESS;
}


/**
 *  定时读取数据函数.
 *  这类设备通常提供读取指定数据块的信息协议，该函数主要实现如下功能：
 *  1、数据的发送和接收
 *  2、更新数据块实时数据的值、数据状态和时间戳
 *  3、对于非tcp通信协议，通常需要在该接口检查连接状态
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *  @param  -[in]  DRVHANDLE hDataBlock: [数据块句柄]
 *
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnReadData(DRVHANDLE hDevice, DRVHANDLE hDataBlock)
{
	//TODO：发送和接收数据

	//TODO：调用驱动框架提供的Drv_UpdateBlockData、Drv_UpdateBlockStatus更新数据块信息

	return DRV_SUCCESS;
}

/**
 *  当有控制命令时该函数被调用.
 *  在该函数中根据传递的参数，向设备下发控制命令。
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *  @param	-[in]  DRVHANDLE hDataBlock : [数据块句柄]
 *  @param	-[in]  int nTagDataType : tag点类型
 *  @param  -[in]  int nTagByteOffset: [tag点在块中的字节偏移量]
 *  @param  -[in]  int nTagBitOffset: [字节内的位偏移量]
 *  @param	-[in]  char *szCmdData : [控制指令]
 *  @param  -[in]  int nCmdDataLenBits: [控制数据长度,单位是bit]
 *
  *  @return : 控制执行反馈结果
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnWriteCmd(DRVHANDLE hDevice, DRVHANDLE hDataBlock, int nTagByteOffset, int nTagBitOffset, char *szCmdData, int nCmdDataLenBits)
{
	//TODO：解析szShortAddr,获取对应的数据块信息

	//TODO：生成控制指令，发送控制信息

	//TODO：处理控制反馈结果
	return 0;
}

/**
 *  添加设备时该函数被调用.
 *  该函数主要针对非tcp连接设备，用户可以通过设备句柄获取设备连接参数，初始化连接设备
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnDeviceAdd(DRVHANDLE hDevice)
{
	//TODO：对于非tcp设备处理设备连接等操作

	return DRV_SUCCESS;
}

/**
 *  删除设备时该函数被调用.
 *  该函数主要针对非tcp连接设备，用户可以通过设备句柄获取设备信息，处理断开设备、释放相关资源等操作
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnDeviceDelete(DRVHANDLE hDevice)
{
	//TODO：对于非tcp设备处理设备断开等操作

	return DRV_SUCCESS;
}


/**
 *  添加数据块时该函数被调用.
 *  用户需要在该函数中返回数据块大小
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *  @param  -[in]  DRVHANDLE hDataBlock: [数据块句柄]
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnDataBlockAdd(DRVHANDLE hDevice, DRVHANDLE hDataBlock)
{
	//TODO：执行数据块相关自定义操作

	return DRV_SUCCESS;
}

/**
 *  删除数据块时该函数被调用.
 *  @param  -[in]  DRVHANDLE hDevice: [设备句柄]
 *  @param  -[in]  DRVHANDLE hDataBlock: [数据块句柄]
 *
 *  @return DRV_SUCCESS: 执行成功
 *
 *  @version     07/20/2012   Initial Version.
 */
CVDRIVER_EXPORTS long OnDataBlockDelete(DRVHANDLE hDevice, DRVHANDLE hDataBlock)
{
	//TODO：执行数据块相关清理操作

	return DRV_SUCCESS;
}


