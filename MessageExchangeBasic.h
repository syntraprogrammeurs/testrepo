#pragma once
#include "csmsg.h"
#include "MessageExchangeImpl.h"

__attribute__((constructor)) void dllLoad();
__attribute__((destructor)) void dllUnload();

#if defined(__cplusplus)
extern "C"
{
#endif
	CSMSG_API_DECL CSME_HANDLE			csme_create();
	CSMSG_API_DECL void					csme_destroy(CSME_HANDLE handle);
	
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_trace_significant_events(CSME_HANDLE handle);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_get_max_size_received_data(CSME_HANDLE handle, uint32_t& size);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_set_max_size_received_data(CSME_HANDLE handle, uint32_t newSize);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_get_timeout(CSME_HANDLE handle, uint16_t& timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_set_timeout(CSME_HANDLE handle, uint16_t timeout);


	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_register_application(CSME_HANDLE handle, const char* applicationName);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_remove_application(CSME_HANDLE handle);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_send(CSME_HANDLE handle, const char* address, uint8_t module, uint8_t id, uint8_t service, uint8_t sessionType, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_request(CSME_HANDLE handle, const char* address, uint8_t module, uint8_t id, uint8_t service, uint8_t sessionType, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, SERVICE_COMPLETION_STATUS& serviceCompletionStatus, unsigned char* receivedData, uint32_t& receivedDataSize, uint8_t& receivedDataPresentation, uint32_t& messageNo, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_receive(CSME_HANDLE handle, SERVICE_COMPLETION_STATUS& serviceCompletionStatus, char* address, uint16_t addressSize, uint8_t& module, uint8_t& id, uint8_t& service, uint8_t& sessionType, uint8_t& serviceClass, unsigned char** receivedData, uint32_t& receivedDataSize, uint8_t& receivedDataPresentation, bool& retry, uint16_t& sequenceNumber, TIME_STAMP& timestampUtc, uint32_t& messageNo, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_receive_data(CSME_HANDLE handle, uint32_t messageNo, SERVICE_COMPLETION_STATUS& serviceCompletionStatus, unsigned char** receivedData, uint32_t& receivedDataSize, uint8_t& receivedDataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE    csme_flush_data(CSME_HANDLE handle, uint32_t messageNo);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_respond(CSME_HANDLE handle, uint32_t messageNo, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_respond_error(CSME_HANDLE handle, uint32_t messageNo, CSMSG_STATUS_TYPE errorCode, CSMSG_STATUS_TYPE applicationErrorCode, uint16_t timeout);

	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_add_unit(CSME_HANDLE handle, const char* address);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_remove_unit(CSME_HANDLE handle, const char* address);

	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_register_application(CSME_HANDLE handle, int32_t serviceRequestID, const char* applicationName);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_remove_application(CSME_HANDLE handle, int32_t serviceRequestID);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_send(CSME_HANDLE handle, int32_t serviceRequestID, const char* address, uint8_t module, uint8_t id, uint8_t service, uint8_t sessionType, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_request(CSME_HANDLE handle, int32_t serviceRequestID, const char* address, uint8_t module, uint8_t id, uint8_t service, uint8_t sessionType, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_receive(CSME_HANDLE handle, int32_t serviceRequestID, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_receive_data(CSME_HANDLE handle, int32_t serviceRequestID, uint32_t messageNo, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_flush_data(CSME_HANDLE handle, int32_t serviceRequestID, uint32_t messageNo);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_respond(CSME_HANDLE handle, int32_t serviceRequestID, uint32_t messageNo, const unsigned char* data, uint32_t dataSize, uint8_t dataPresentation, uint16_t timeout);
	CSMSG_API_DECL CSMSG_STATUS_TYPE	csme_launch_respond_error(CSME_HANDLE handle, int32_t serviceRequestID, uint32_t messageNo, CSMSG_STATUS_TYPE errorCode, CSMSG_STATUS_TYPE applicationErrorCode, uint16_t timeout);
			
	CSMSG_API_DECL void					csme_on_register_application_callback(CSME_HANDLE handle, CSME_ON_REGISTER_APPLICATION_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_remove_application_callback(CSME_HANDLE handle, CSME_ON_REMOVE_APPLICATION_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_send_callback(CSME_HANDLE handle, CSME_ON_SEND_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_request_callback(CSME_HANDLE handle, CSME_ON_REQUEST_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_receive_callback(CSME_HANDLE handle, CSME_ON_RECEIVE_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_receive_data_callback(CSME_HANDLE handle, CSME_ON_RECEIVE_DATA_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_flush_data_callback(CSME_HANDLE handle, CSME_ON_FLUSH_DATA_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_respond_callback(CSME_HANDLE handle, CSME_ON_RESPOND_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_connection_info_callback(CSME_HANDLE handle, CSME_ON_CONNECTION_INFO_CALLBACK callback);
	CSMSG_API_DECL void					csme_on_filter_conflict_info_callback(CSME_HANDLE handle, CSME_ON_FILTER_CONFLICT_INFO_CALLBACK callback);

#if defined(__cplusplus)
}
#endif
