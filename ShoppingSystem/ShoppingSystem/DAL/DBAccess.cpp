#include "..\framework\stdafx.h"
#include "DBAccess.h"

DBAccess::DBAccess() {
    if (!adoConn.ConnectAccess(_T("ShoppingDB.mdb")))
        throw _T("�������ݿ��쳣��");
}

DBAccess::~DBAccess() {
    adoConn.Close();
}

BOOL DBAccess::executeQuery(CString sql, CAdoRecordSet& adoRecordSet) {
    adoRecordSet.SetAdoConnection(&adoConn);
    return adoRecordSet.Open((LPCTSTR) sql);
}

long DBAccess::executeNonQuery(CString sql) {
    long affected = 0;
    adoConn.Execute((LPCTSTR) sql, &affected, adExecuteNoRecords);
    return affected;
}