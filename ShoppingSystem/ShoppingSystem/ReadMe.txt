========================
ShoppingSystem��Ŀ����
========================
    ����Ŀ��һ����MFC��ܱ�д��C/S��Ŀ����Ҫ���ܰ����û���¼����Ʒ��ɾ��ġ�������㡢����������Ʒ��ѯ���ۻ�Ա����ȡ�

========================
ShoppingSystem�ļ�Ŀ¼
========================
    ����Ŀ��������ܹ���˼���д�����
    1��FrameworkĿ¼��mfc������ɵ��ļ���������
        resource.h
        ShoppingSystem.h  //��������򣬰���theApp
        stdafx.h

    2��ToolsĿ¼��������Ŀ�õ�������ת�����ߣ�������
        Tools.h  //���ͺ͸�����ת��ΪCString

    3��DALĿ¼�����ݿ�����࣬������
        Ado.h  //�����ADO
        AdoCommand.h  //�����ADO
        AdoRecordSet.h  //�����ADO
        DBAccess.h  ��װ��ʹ��Sql�����з������ݼ��Ĳ�ѯ�������ݼ�����ɾ��

    4��BLLĿ¼��������Ŀ��ҵ���߼��㣬������
        AdminManager.h  //����Ա������
        GoodsManager.h  //��Ʒ������
        GSalesManager.h  //������㡢����������Ʒ��ҵ���߼���
        LoginManager.h  //����Ա���ۻ�Ա��¼����Ļ��࣬������AdminManager��SalesmanManager������
        SalesmanManager.h  //�ۻ�Ա������

    5��EntityĿ¼�Ƕ�Ӧ���ݿ�������ʵ����
        Admin.h
        Goods.h
        GSales.h
        Salesman.h

========================
���ݿ���ƺ͹�������ĵ�
========================
    ���files�ļ����µ�����˵���鲿��