#include "logger_capi.h"
#include "logger_writer.h"
#include <stdarg.h>

using namespace LOGGER;

int32_t start_log_thread()
{
	return CLogger::Start();
}

int32_t stop_log_thread()
{
	return CLogger::Stop();
}

int32_t set_log_dir(const char *szLogDir)
{
	return CLogger::SetLogDir(szLogDir);
}

void write_debug_log(const char *szLoggerName, const char *szFormat, ...)
{
	CLoggerWriter *pLoggerWriter = CLogger::GetLogger(szLoggerName);
	va_list vaList;
	va_start(vaList, szFormat);
	pLoggerWriter->Debug(szFormat, __FILE__, __LINE__, vaList);
	va_end(vaList);
}
