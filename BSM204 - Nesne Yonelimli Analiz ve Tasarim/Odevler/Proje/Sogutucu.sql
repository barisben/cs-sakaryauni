--
-- PostgreSQL database dump
--

-- Dumped from database version 13.2
-- Dumped by pg_dump version 13.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: KritikSicaklikLog_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KritikSicaklikLog_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KritikSicaklikLog_id_seq" OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: KritikSicaklikLog; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KritikSicaklikLog" (
    id integer DEFAULT nextval('public."KritikSicaklikLog_id_seq"'::regclass) NOT NULL,
    tarih timestamp without time zone NOT NULL,
    sicaklik real NOT NULL
);


ALTER TABLE public."KritikSicaklikLog" OWNER TO postgres;

--
-- Name: Kullanici_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kullanici_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kullanici_id_seq" OWNER TO postgres;

--
-- Name: Kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kullanici" (
    id integer DEFAULT nextval('public."Kullanici_id_seq"'::regclass) NOT NULL,
    "kullaniciAdi" character varying(30) NOT NULL,
    sifre character varying(20) NOT NULL
);


ALTER TABLE public."Kullanici" OWNER TO postgres;

--
-- Data for Name: KritikSicaklikLog; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: Kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Kullanici" VALUES
	(1, 'baris', 'baris'),
	(2, 'yilmaz', 'yilmaz');


--
-- Name: KritikSicaklikLog_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KritikSicaklikLog_id_seq"', 1, false);


--
-- Name: Kullanici_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kullanici_id_seq"', 2, true);


--
-- Name: KritikSicaklikLog KritikSicaklikLog_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KritikSicaklikLog"
    ADD CONSTRAINT "KritikSicaklikLog_pkey" PRIMARY KEY (id);


--
-- Name: Kullanici Kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "Kullanici_pkey" PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

