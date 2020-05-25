// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.0.0.
// **********************************************************************

#ifndef __HELLO_H_
#define __HELLO_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace TestApp
{

    /* callback of async proxy for client */
    class HelloPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~HelloPrxCallback(){}
        virtual void callback_testHello(tars::Int32 ret,  const std::string& r)
        { throw std::runtime_error("callback_testHello() override incorrect."); }
        virtual void callback_testHello_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_testHello_exception() override incorrect."); }

        virtual void callback_testSHello(tars::Int32 ret,  const std::string& sRsp)
        { throw std::runtime_error("callback_testSHello() override incorrect."); }
        virtual void callback_testSHello_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_testSHello_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Hello_all[]=
            {
                "testHello",
                "testSHello"
            };
            pair<string*, string*> r = equal_range(__Hello_all, __Hello_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Hello_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testHello_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string r;
                    _is.read(r, 3, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_testHello(_ret, r);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testSHello_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string sRsp;
                    _is.read(sRsp, 2, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_testSHello(_ret, sRsp);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<HelloPrxCallback> HelloPrxCallbackPtr;

    /* callback of coroutine async proxy for client */
    class HelloCoroPrxCallback: public HelloPrxCallback
    {
    public:
        virtual ~HelloCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Hello_all[]=
            {
                "testHello",
                "testSHello"
            };

            pair<string*, string*> r = equal_range(__Hello_all, __Hello_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Hello_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testHello_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string r;
                        _is.read(r, 3, true);
                        setResponseContext(msg->response->context);

                        callback_testHello(_ret, r);

                    }
                    catch(std::exception &ex)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_testHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_testSHello_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string sRsp;
                        _is.read(sRsp, 2, true);
                        setResponseContext(msg->response->context);

                        callback_testSHello(_ret, sRsp);

                    }
                    catch(std::exception &ex)
                    {
                        callback_testSHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_testSHello_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<HelloCoroPrxCallback> HelloCoroPrxCallbackPtr;

    /* proxy for client */
    class HelloProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 testHello(tars::Int32 index,const std::string & s,std::string &r,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(index, 1);
            _os.write(s, 2);
            _os.write(r, 3);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"testHello", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(r, 3, true);
            return _ret;
        }

        void async_testHello(HelloPrxCallbackPtr callback,tars::Int32 index,const std::string &s,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(index, 1);
            _os.write(s, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testHello", _os, context, _mStatus, callback);
        }
        
        void coro_testHello(HelloCoroPrxCallbackPtr callback,tars::Int32 index,const std::string &s,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(index, 1);
            _os.write(s, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testHello", _os, context, _mStatus, callback, true);
        }

        tars::Int32 testSHello(const std::string & sReq,std::string &sRsp,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sReq, 1);
            _os.write(sRsp, 2);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"testSHello", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(sRsp, 2, true);
            return _ret;
        }

        void async_testSHello(HelloPrxCallbackPtr callback,const std::string &sReq,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sReq, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testSHello", _os, context, _mStatus, callback);
        }
        
        void coro_testSHello(HelloCoroPrxCallbackPtr callback,const std::string &sReq,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sReq, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testSHello", _os, context, _mStatus, callback, true);
        }

        HelloProxy* tars_hash(int64_t key)
        {
            return (HelloProxy*)ServantProxy::tars_hash(key);
        }

        HelloProxy* tars_consistent_hash(int64_t key)
        {
            return (HelloProxy*)ServantProxy::tars_consistent_hash(key);
        }

        HelloProxy* tars_set_timeout(int msecond)
        {
            return (HelloProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "HelloProxy"; }
    };
    typedef tars::TC_AutoPtr<HelloProxy> HelloPrx;

    /* servant for server */
    class Hello : public tars::Servant
    {
    public:
        virtual ~Hello(){}
        virtual tars::Int32 testHello(tars::Int32 index,const std::string & s,std::string &r,tars::TarsCurrentPtr current) = 0;
        static void async_response_testHello(tars::TarsCurrentPtr current, tars::Int32 _ret, const std::string &r)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("r", r);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(r, 3);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

        virtual tars::Int32 testSHello(const std::string & sReq,std::string &sRsp,tars::TarsCurrentPtr current) = 0;
        static void async_response_testSHello(tars::TarsCurrentPtr current, tars::Int32 _ret, const std::string &sRsp)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("sRsp", sRsp);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(sRsp, 2);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __TestApp__Hello_all[]=
            {
                "testHello",
                "testSHello"
            };

            pair<string*, string*> r = equal_range(__TestApp__Hello_all, __TestApp__Hello_all+2, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __TestApp__Hello_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    tars::Int32 index;
                    std::string s;
                    std::string r;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("index", index);
                        tarsAttr.get("s", s);
                        tarsAttr.getByDefault("r", r, r);
                    }
                    else
                    {
                        _is.read(index, 1, true);
                        _is.read(s, 2, true);
                        _is.read(r, 3, false);
                    }
                    tars::Int32 _ret = testHello(index,s,r, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("r", r);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(r, 3);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    std::string sReq;
                    std::string sRsp;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("sReq", sReq);
                        tarsAttr.getByDefault("sRsp", sRsp, sRsp);
                    }
                    else
                    {
                        _is.read(sReq, 1, true);
                        _is.read(sRsp, 2, false);
                    }
                    tars::Int32 _ret = testSHello(sReq,sRsp, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("sRsp", sRsp);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(sRsp, 2);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif